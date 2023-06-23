#!/bin/bash

ulimit -s unlimited

if [ "$1" == "no" ]; then
	echo " "
else
	./check.sh
	OUT=$?

	if [ $OUT -eq 1 ];then
   		echo "All dependencies are installed! We haven't check your hard drive type. If you are not using SSD, then the timing results may be affected. The experiment will run now..."
	else
   		echo "You are missing some dependendencies! Results may be affected."
   		read -p "Do you still want to continue? (y/n)?"
   		if [ $REPLY == "n" ]; then
			echo "Exiting..."
		exit 1
   		fi
	fi
fi


rm -r -f Host_BENEFICIARY
cd Experiment
cd pidgin-idct
rm -r -f Host_BENEFICIARY TEMP-* TransplantCode-* Temp/*
cd ..

./gentrans --seeds_file pidgin-idct/seed-1.in --compiler_options pidgin-idct/CFLAGS --host_target pidgin-idct/Host/pidgin-2.10.9/libpurple/ft.c --donor_target pidgin-idct/Donor/dct.c --donor_folder pidgin-idct/Donor/ --workspace pidgin-idct/ --core_function idct  --host_project pidgin-idct/Host

cd pidgin-idct
cp -r -f Host_BENEFICIARY ../../
rm -r -f Host_BENEFICIARY TEMP-* TransplantCode-* Temp/*
cd ../../


# Run test suites
./runTestSuites.sh
