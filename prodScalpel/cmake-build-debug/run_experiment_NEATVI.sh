#!/bin/bash

ulimit -s 65353


for i in 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20; do

	echo "RUN: $i"  
	ulimit -s 65353
	if ./autoScalpel_spl --seeds_file Transplant-PRODUCT_B/T_NEATVI/seed-1.in --transplant_log Transplant-PRODUCT_B/T_NEATVI/LOG/ --compiler_options Transplant-PRODUCT_B/T_NEATVI/CFLAGS --donor_folder Transplant-PRODUCT_B/T_NEATVI/Donor/NEATVI/ --workspace Transplant-PRODUCT_B/T_NEATVI/ --txl_tools_path TXL/ --functions_target Transplant-PRODUCT_B/T_NEATVI/coreFunctions.in --host_project Transplant-PRODUCT_B/ProductBase/NEATVI --donor_entry_function main --donor_entry_file main.c --conditional_directives F_DIR_INIT --product_base T01; then
 
         #Run post-operative tests
        cd Transplant-PRODUCT_B/ProductBase/NEATVI-T01
        ./test.sh test_output.txt DIR_INIT NEATVI $i
       
       #copy test_output file to the experiment directory
        cp -r -f test_output.txt /Users/leandrosouza/CLion_workspace/muScalpel_spl/cmake-build-debug/Transplant-PRODUCT_B/T_NEATVI/LOG
        
        cd /Users/leandrosouza/CLion_workspace/muScalpel_spl/cmake-build-debug/
        #copy DONOR NEATVI_T0? to the experiment directory
        cp -r -f Transplant-PRODUCT_B/T_NEATVI /Users/leandrosouza/CLion_workspace/EXPERIMENT_RESULT3/NEATVI_T0$i
        
        #Copy Host post-operative to the experiment directory
        cp -r -f Transplant-PRODUCT_B/ProductBase/NEATVI-T01 /Users/leandrosouza/CLion_workspace/EXPERIMENT_RESULT3/NEATVI-T01_NEATVI_T0$i
        
        #Delete Host post-operative
        rm -r -f Transplant-PRODUCT_B/ProductBase/NEATVI-T01
        
		#cp -r -f Transplant-PRODUCT_B/T_NEATVI /Users/leandrosouza/CLion_workspace/EXPERIMENT_RESULT/NEATVI_T0$i
		#cp -r -f Transplant-PRODUCT_B/ProductBase/NEATVI-T01 /Users/leandrosouza/CLion_workspace/EXPERIMENT_RESULT/NEATVI-T01_NEATVI_T0$i
		#rm -r -f Transplant-PRODUCT_B/ProductBase/NEATVI-T01
	else
		echo "RUN: $i Execution error!!! Aborting..." 1>&2
		#Copy Host post-operative to the experiment directory
        cp -r -f Transplant-PRODUCT_B/ProductBaseT_/NEATVI /Users/leandrosouza/CLion_workspace/EXPERIMENT_RESULT3/NEATVI_T0$i
	fi

done

echo "FINISHED 20 RUNNING"

./test.sh test_output.txt DIR_INIT NEATVI 01
	
