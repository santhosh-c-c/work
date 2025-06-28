#include "uart.h"
int main()
{
	uart_setup(PORT_A, PIN(0), OUTMODE);
	uart_setup(PORT_A, PIN(1), INMODE);
	
	uart_initiate(PORT_A, PIN(0), PIN(1), "hello world");

	return 0;
}

/*
#include "uart.h"
int main()
{
	uart_init(PORT_A, PIN(0), OUTMODE);
	uart_init(PORT_A, PIN(1), INMODE);

	uart_tx(PORT_A, PIN(0), "hello world");
	uart_rx(PORT_A, PIN(1));
	return 0;
}
*/
