mkdir backup_data
cd backup_data
touch data.txt
echo "Sample Text" > data.txt
ls -l
cp data.txt data_backup.txt
mkdir archives
mv data_backup.txt archives
grep -w Text data.txt
file data.txt
cat data.txt | hd
cp data.txt test.txt
scp /home/santhosh/Problem3/backup_data/test.txt thangamareeswari@192.168.1.104:/home/thangamareeswari/new1
rm archives/data_backup.txt
history 10
