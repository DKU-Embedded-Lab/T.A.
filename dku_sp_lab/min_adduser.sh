#!/bin/bash

passwd="sys123456" 
argc=$#

if [ $argc -lt 1 ] ; then

    echo "Usage : ./min_adduser.sh [class_list] "
    exit 0
fi


while read line
do 
echo "sys$line"
    deluser --remove-home sys$line
    mkdir /home/16_2_1/sys$line 
	useradd sys$line -d /home/16_2_1/sys$line -s /bin/bash -p sys123456
	cp defaultvimrc /home/16_2_1/sys$line/.vimrc
	cp defaultbashrc /home/16_2_1/sys$line/.bashrc
	chown sys$line:sys$line /home/16_2_1/sys$line/.vimrc
	chown sys$line:sys$line /home/16_2_1/sys$line/.bashrc
	chown sys$line:sys$line /home/16_2_1/sys$line 
    chmod 711 sys$line
done < $1
