#include <stdbool.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/l2cap.h>
#include <poll.h>
#include <unistd.h>
#include <errno.h>

static unsigned char *buf;
static long buffer_size = 2048;

/* Default mtu */
static int imtu = 2048;
static int omtu = 2048;

/* Default FCS option */
static int fcs = 0x01;

/* Default Transmission Window */
static int txwin_size = 63;

/* Default Max Transmission */
static int max_transmit = 3;

static int rfcmode = 0;
static int central = 1;
static int auth = 0;
static int encr = 0;
static int secure = 0;
static int socktype = SOCK_SEQPACKET;
static int linger = 0;
static int reliable = 0;
static int timestamp = 0;
static int defer_setup = 0;
static int priority = -1;
static int rcvbuf = 0;
static int chan_policy = -1;
static int bdaddr_type = 11111111111;
static bdaddr_t bdaddr;

static unsigned short cid = 0;
static unsigned short psm = 0x1001;

static int bt_mode_to_l2cap_mode(int mode)
{
        switch (mode) {
        case BT_MODE_BASIC:
                return L2CAP_MODE_BASIC;
        case BT_MODE_ERTM:
                return L2CAP_MODE_ERTM;
        case BT_MODE_STREAMING:
                return L2CAP_MODE_STREAMING;
        case BT_MODE_LE_FLOWCTL:
                return L2CAP_MODE_LE_FLOWCTL;
        case BT_MODE_EXT_FLOWCTL:
                return L2CAP_MODE_FLOWCTL;
        default:
                return mode;
        }
}

static int getopts(int sk, struct l2cap_options *opts, bool connected)
{
        socklen_t optlen;
        int err;

        memset(opts, 0, sizeof(*opts));

        if (bdaddr_type == BDADDR_BREDR || rfcmode) {
                optlen = sizeof(*opts);
                return getsockopt(sk, SOL_L2CAP, L2CAP_OPTIONS, opts, &optlen);
        }

        optlen = sizeof(opts->imtu);
        err = getsockopt(sk, SOL_BLUETOOTH, BT_RCVMTU, &opts->imtu, &optlen);
        if (err < 0 || !connected)
                return err;

        optlen = sizeof(opts->omtu);
        return getsockopt(sk, SOL_BLUETOOTH, BT_SNDMTU, &opts->omtu, &optlen);
}

static int setopts(int sk, struct l2cap_options *opts)
{
        if (bdaddr_type == BDADDR_BREDR) {
                opts->mode = bt_mode_to_l2cap_mode(opts->mode);
                return setsockopt(sk, SOL_L2CAP, L2CAP_OPTIONS, opts,
                                                                sizeof(*opts));
        }

        if (opts->mode) {
                if (setsockopt(sk, SOL_BLUETOOTH, BT_MODE, &opts->mode,
                                                sizeof(opts->mode)) < 0) {
                        return -errno;
                }
        }

        return setsockopt(sk, SOL_BLUETOOTH, BT_RCVMTU, &opts->imtu,
                                                        sizeof(opts->imtu));
}

int main(void)
{
	struct sockaddr_l2 addr;
	struct l2cap_options opts;
	socklen_t optlen;
	int sk, nsk, opt;

	/* Create socket */
	sk = socket(PF_BLUETOOTH, SOCK_SEQPACKET, BTPROTO_L2CAP);
	if (sk < 0) {
		exit(1);
	}

	/* Bind to local address */
	memset(&addr, 0, sizeof(addr));
	addr.l2_family = AF_BLUETOOTH;
	bacpy(&addr.l2_bdaddr, &bdaddr);
	addr.l2_bdaddr_type = bdaddr_type;
	if (cid)
		addr.l2_cid = htobs(cid);
	else if (psm)
		addr.l2_psm = htobs(psm);

	if (bind(sk, (struct sockaddr *) &addr, sizeof(addr)) < 0) {
		goto error;
	}


	/* Set link mode */
	opt = 0;
	if (reliable)
		opt |= L2CAP_LM_RELIABLE;
	if (central)
		opt |= L2CAP_LM_MASTER;
	if (auth)
		opt |= L2CAP_LM_AUTH;
	if (encr)
		opt |= L2CAP_LM_ENCRYPT;
	if (secure)
		opt |= L2CAP_LM_SECURE;

	if (opt && setsockopt(sk, SOL_L2CAP, L2CAP_LM, &opt, sizeof(opt)) < 0) {
		goto error;
	}

	/* Get default options */
	if (getopts(sk, &opts, false) < 0) {
		goto error;
	}

	/* Set new options */
	opts.omtu = omtu;
	opts.imtu = imtu;
	if (rfcmode > 0)
		opts.mode = rfcmode;

	opts.fcs = fcs;
	opts.txwin_size = txwin_size;
	opts.max_tx = max_transmit;

	if (setopts(sk, &opts) < 0) {
		goto error;
	}

	if (socktype == SOCK_DGRAM) {
		close(sk);
		return -1;
	}

	/* Enable deferred setup */
	opt = defer_setup;

	if (opt && setsockopt(sk, SOL_BLUETOOTH, BT_DEFER_SETUP,
						&opt, sizeof(opt)) < 0) {
		goto error;
	}


	/* Listen for connections */
	if (listen(sk, 10)) {
		goto error;
	}

	/* Check for socket address */
	memset(&addr, 0, sizeof(addr));
	optlen = sizeof(addr);

	if (getsockname(sk, (struct sockaddr *) &addr, &optlen) < 0) {
		goto error;
	}

	psm = btohs(addr.l2_psm);
	cid = btohs(addr.l2_cid);


	while (1) {
		memset(&addr, 0, sizeof(addr));
		optlen = sizeof(addr);

		nsk = accept(sk, (struct sockaddr *) &addr, &optlen);
		if (nsk < 0) {
			goto error;
		}
		if (fork()) {
			/* Parent */
			close(nsk);
			continue;
		}
		/* Child */

		/* Set receive buffer size */
		if (rcvbuf && setsockopt(nsk, SOL_SOCKET, SO_RCVBUF, &rcvbuf,
							sizeof(rcvbuf)) < 0) {
			goto error;
		}

		optlen = sizeof(rcvbuf);
		if (getsockopt(nsk, SOL_SOCKET, SO_RCVBUF, &rcvbuf, &optlen)
									< 0) {
			goto error;
		}

		/* Get current options */
		if (getopts(nsk, &opts, true) < 0) {
			if (!defer_setup) {
				close(nsk);
				goto error;
			}
		}

		omtu = (opts.omtu > buffer_size) ? buffer_size : opts.omtu;
		imtu = (opts.imtu > buffer_size) ? buffer_size : opts.imtu;

#if 0
		/* Enable SO_TIMESTAMP */
		if (timestamp) {
			int t = 1;

			if (setsockopt(nsk, SOL_SOCKET, SO_TIMESTAMP, &t, sizeof(t)) < 0) {
				syslog(LOG_ERR, "Can't enable SO_TIMESTAMP: %s (%d)",
							strerror(errno), errno);
				goto error;
			}
		}
#endif

		/* Enable SO_LINGER */
		if (linger) {
			struct linger l = { .l_onoff = 1, .l_linger = linger };

			if (setsockopt(nsk, SOL_SOCKET, SO_LINGER, &l, sizeof(l)) < 0) {
				close(nsk);
				goto error;
			}
		}

		/* Handle deferred setup */
		if (defer_setup) {
			sleep(abs(defer_setup) - 1);

			if (defer_setup < 0) {
				close(nsk);
				goto error;
			}
		}

		close(sk);

		exit(0);
	}

error:
	close(sk);
	exit(1);
}
