#!/bin/bash

ulimit -s 65353


for i in 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20; do

	echo "RUN: $i"  
	ulimit -s 65353
	if  ./autoScalpel_spl --seeds_file Transplant-PRODUCT_B/T_MYTAR/seed-1.in --transplant_log Transplant-PRODUCT_B/T_MYTAR/LOG/ --compiler_options Transplant-PRODUCT_B/T_MYTAR/CFLAGS --donor_folder Transplant-PRODUCT_B/T_MYTAR/Donor/MYTAR/ --workspace Transplant-PRODUCT_B/T_MYTAR/ --txl_tools_path TXL/ --functions_target Transplant-PRODUCT_B/T_MYTAR/coreFunctions.in --host_project Transplant-PRODUCT_B/ProductBase/NEATVI --donor_entry_function main --donor_entry_file main.c --conditional_directives F_WRITE_ARCHIVE --product_base T2; then
        
        #Run post-operative tests
        cd Transplant-PRODUCT_B/ProductBase/NEATVI-T2
        ./test_product_line.sh test_output.txt
       
       #copy test_output file to the experiment directory
        cp -r -f test_output.txt /Users/leandrosouza/CLion_workspace/muScalpel_spl/cmake-build-debug/Transplant-PRODUCT_B/T_MYTAR/LOG
        
        cd /Users/leandrosouza/CLion_workspace/muScalpel_spl/cmake-build-debug/
        #copy DONOR MYTAR_T0? to the experiment directory
        cp -r -f Transplant-PRODUCT_B/T_MYTAR /Users/leandrosouza/CLion_workspace/EXPERIMENT_RESULT3/MYTAR_T0$i
        
        #Copy Host post-operative to the experiment directory
		cp -r -f Transplant-PRODUCT_B/ProductBase/NEATVI-T2 /Users/leandrosouza/CLion_workspace/EXPERIMENT_RESULT3/MYTAR-T2_NEATVI_T0$i
        
        #Delete Host post-operative 
		rm -r -f Transplant-PRODUCT_B/ProductBase/NEATVI-T2
	else
		echo "RUN: $i Execution error!!! Aborting..." 1>&2
        #copy DONOR MYTAR_T0? to the experiment directory
        cp -r -f Transplant-PRODUCT_B/T_MYTAR /Users/leandrosouza/CLion_workspace/EXPERIMENT_RESULT3/MYTAR_T0$i
        
		#exit 1
	fi

done

echo "FINISHED 20 RUNNING"  
	
