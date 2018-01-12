#! /bin/bash
script_dir=$(cd "$(dirname "$0")" && pwd)

while read line
do
	echo "ulimit -u 100" >> ${script_dir}/sys${line}/.bashrc
	source ${script_dir}/sys${line}/.bashrc
done < $1
