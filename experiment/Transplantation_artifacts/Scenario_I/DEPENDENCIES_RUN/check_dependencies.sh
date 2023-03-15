#!/bin/bash

ulimit -s 65353

if [ "$1" == "no" ]; then
	echo " "
else
	./check.sh
	OUT=$?

	if [ $OUT -eq 1 ];then
   		echo "All dependencies are installed! We haven't check your hard drive type. If you are not using SSD, then the timing results may be affected. The experiment will run now..."
	else
   		echo "You are missing some dependendencies! Results may be affected. Please send the file dependencies_log.txt to the experiment researchers."
   		read -p "Do you still want to continue? (y/n)?"
   		if [ $REPLY == "n" ]; then
			echo "Exiting..."
		exit 1
   		fi
	fi
fi


make
