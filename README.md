README

#AUTOTRANSPLANTATION SPL
   The autotransplantation tool for product derivation using automated (multi-organ) software transplantation approach called FOUNDRY

## Versioning

For the versions available, see the [tags on this repository](https://github.com/autotransplantation-spl/foundry.github.io/blob/main/prodScalpel/prodScalpel). 

## Getting Started

FROM MacOS Catalina 10.15.2 and ubuntu:16.04
MAINTAINER Leandro Souza "leandro.souza@ifba.edu.br"

### Prerequisites

#install the requirements for prodScalpel

FOR MACOS
    For correctly compile, prodScalpel require
    • Xcode Command Line Tools;
    • gcc;
    • autoconf;
    • cflow
    • doxygen;
    • automake;
    • libglib2.0;
    • make;
    • libgcrypt20;
    • check;
    • Pkg-config;
    • GNU Diff;
    • and with at least 16 GB memory.

For correctly execution, prodScalpel requires:
    • Autoconf;
    • libtool;
    • Pkg-config;
    • Check ;
    • cflow;
    • doxygen;
    • and GNU Diff

FOR LINUX:

RUN apt-get update && apt-get install -y git doxygen wget gcc g++ gfortran autoconf automake libtool flex bison vim cflow make check pkg-config libglib2.0-dev libgcrypt20 diff

RUN cp /usr/bin/gcc-5 /usr/bin/gcc 
RUN cp /usr/bin/g++-5 /usr/bin/g++
RUN cp /usr/bin/gfortran-5 /usr/bin/gfortran

### Installing

A step by step series of examples that tell you how to get a development env running (In process)

### EXPERIMENT : FOLDER STRUCTURE
      ROOT
         |--autoScalpel.exec                 # Exec file
         |--ErrorFile.out                    # TXL errors
         |--Transplant_<donor-host names>    # Current experiment directory
            |--CFLAGS.txt                    # Flags to the current experiment
            |--coreFunctions.in              # Core function input list (Feature entry points)
            |--Donor                         # Donor system directory
            |--Doxygen_<donor_name>          # Doxygen directory
            |--Host                          # Host system folder
            |--Temp                          # Temporary folder for the transplant process
            |--TempDonorFiles                # Temporary folder for Donor system
            |--TempImplantationDirectory     # Temporary folder for Implantation files
            |--TempSourceFiles               # Temporary folder for the transplant process
            |--TestSuites                    # Testing directory
            |__TransplantCode                # IceBox directory
         |--TXL (For macOS)                  # TXL for macOS directory
         |__TXL_LINUX (For LINUX)            # TXL for Linux directory
      ...                                    # Tool source code

## Running the tests

### RUN - The complete command, as it should be pasted is:

Transplanting feature F_WRITE_ARCHIVE from Mytar-C-EDITOR
    prodScalpel --seeds_file <transplantation_directory>/seed-1.in --compiler_options <transplantation_directory>/CFLAGS --host_target <transplantation_directory>/productBase/insert_point_file.c --donor_target <donor_directory>/Donor/organ_souce_file.c --donor_folder <donor_directory>/Donor/ --workspace <transplantation_directory>/ --core_function <core_funtion_name> --host_project <transplantation_directory>/ProductBase

You should run this from EXPERIMENT folder. The Organ is automatically grafted into the host program, so, for subsequent 
runs the original version of the host must be restored. If you wish to run prodScalpel on your own transplants, you will 
need to keep the same folder structure as shown in our examples. The main parameters of autoScalpel are:

    * --exclude_functions /path/to/file:(optional parameter) → exclude some functions from the transplantation algorithm. 
The functions names must be written in a text file: foo bar .

    * --seeds_file /path/to/file: (required) take the seeds from a file. The file must contain 7 lines of 4 numbers each, as in this example.

    * --transplant_log /path/to/folder/ : (optional) log the results of the transplantation operations, in every generation.

    * --compiler_options /path/to/file : (optional) required if the compilation of the code in donor requires additional options or libraries. The format of this file is: CFLAGS = `libgcrypt-config --libs` . The variable CFLAGS contains all the additional dependencies.

    * --donor_folder /path/to/folder/ : (required) the folder where is the source code of the donor.

    * --workspace /path/to/folder/ : (required) the workspace of the transplantation. This is /path/to/Cflow-IDCT_Transplant/ in the above example.

    * --txl_tools_path /path/to/folder/ : (optional) used when the binary files with extension *.x are in a different place than prodScalpel

    * --host_project /path/to/folder :(required) the folder where is the source code of the host.

    * --donor_entry_function /path/to/file : (required) the function in the donor that correspond to its entry_point (generally  the main function).

    * --donor_entry_file: /path/to/file : (required) the file in the donor that contains the entry_point (generally main.c).

    * --conditional_directives: (optional) directive in case when the organ and host must be merged. ProdScalpel introduces variability into the organ by inserting this conditional directive around the organ’s code, making it variable.

    * --product_base : (required) the version of product base after the organ transplantation process. 

Additional parameters:
    * --exclude_functions /path/to/file: (optional) exclude some functions from the transplantation algorithm. 
    * --transplant_statistics /path/to/file: (optional) log statistics about the transplantation operation
    * --urandom_seeds :   prodScalpel will take its seeds from /dev/urandom
    * --random_seeds :   prodScalpel will take its seeds from /dev/random. This may take a while. The default option is --urandom_seeds.

For a new organ transplantation change the file coreFunctions.in. For example, to transplant the feature write_archive from MYTAR to the product base NEATVI the complete command, as it should be pasted in the file is:
    * --coreFunction write_archive --donorSystem MYTAR --donorFileTarget Transplant-PRODUCT_BASE/Donor/append.c --hostFileTarget Transplant-PRODUCT_BASE/ProductBase/NEATVI/ex.c

Where:
    * --core_function function_name : (required) the entry point of the functionality to transplant.
    * --donorSystem: (required) the donor system name.
    * --donor_target /path/to/file : (required) the file in the donor, with the function annotated for transplantation.
    * --host_target /path/to/file : (required) the file in the host that contains the __ADDGRAFTHERE__JUSTHERE annotation. This annotation is required, and it marks the place where the organ will be added.


### The default option is --urandom_seeds.

    * --compiler_options /path/to/file :(optional parameter) → Required if the compilation of the code in donor requires additional 
options or libraries. The format of this file is: CFLAGS = `libgcrypt-config --libs` . The variable CFLAGS contains all the additional dependencies.

    * --donor_folder /path/to/folder/ :(required parameter) → the folder where is the source code of the donor

    * --workspace /path/to/folder/ :(required parameter) → the workspace of the transplantation. This is /path/to/Cflow-IDCT_Transplant/ in the above example.

    * --txl_tools_path /path/to/folder/ :(optional parameter) → used when the binary files with extension .x are in a different place than muScalpel

    * --host_project /path/to/folder :(required parameter) → the folder where is the source code of the host.

    * --donor_entry_function /path/to/file : (required parameter) → the function in the donor that correspond to its entry_point (generally  the main function).

    * --donor_entry_file: /path/to/file : (required parameter) → the file in the donor that contains the entry_point (generally main.c).

    * --conditional_directives:(optional parameter) Directive in case when the organ and host must be merged

### For a new experiment:

Change the file: coreFunctions.in
Ex: --coreFunction write_archive --donorSystem mytar --donorFileTarget Transplant-mytar/Donor/append.c --hostFileTarget Transplant-mytar/Host/NEATVI/ex.c

## Deployment

## Authors
 Created by Marginean Alexandru on 27/02/14 and evolved by Leandro Oliveira de Souza  on 15/05/2017

## License
 Copyright (c) 2014 Marginean Alexandru and 2017 Leandro Oliveira de Souza. All rights reserved.
