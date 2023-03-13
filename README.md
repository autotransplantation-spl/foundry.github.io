README

#AUTOTRANSPLANTATION SPL
   The autotransplantation tool for product derivation using automated (multi-organ) software transplantation approach called FOUNDRY

## Versioning

For the versions available, see the [tags on this repository](https://github.com/leandro-souza/autoScalpel_spl/releases). 

## Getting Started

FROM MacOS Catalina 10.15.2 and ubuntu:16.04
MAINTAINER Leandro Souza "leandro.souza@ifba.edu.br"

### Prerequisites

#install the requirements for autoScalpel
RUN apt-get update && apt-get install -y git doxygen wget gcc g++ gfortran autoconf automake libtool flex bison vim cflow make check pkg-config libglib2.0-dev libgcrypt20

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
./autoScalpel_spl --seeds_file Transplant_c-editor/seed-1.in --compiler_options Transplant_c-editor/CFLAGS --donor_folder Transplant_c-editor/Donor/mytar/ --workspace Transplant_c-editor/ --txl_tools_path TXL/ --functions_target Transplant_c-editor/coreFunctions.in --host_project Transplant_c-editor/Host --donor_entry_function main --donor_entry_file main.c --conditional_directives F_WRITE_ARCHIVE

Transplanting feature F_WRITE from Mytar-PIDGIN
./muScalpel_spl --seeds_file Transplant-mytar/seed-1.in --compiler_options Transplant-mytar/CFLAGS --donor_folder Transplant-mytar/Donor/ --workspace Transplant-mytar/ --txl_tools_path TXL/ --functions_target Transplant-mytar/coreFunctions.in --host_project Transplant-mytar/Host --donor_entry_function main --donor_entry_file main.c --conditional_directives F_WRITE_ARCHIVE

You should run this from EXPERIMENT folder. The Organ is automatically grafted into the host program, so, for subsequent 
runs the original version of the host must be restored. If you wish to run muScalpel on your own transplants, you will 
need to keep the same folder structure as shown in our examples. The main parameters of autoScalpel are:

    * --exclude_functions /path/to/file:(optional parameter) → exclude some functions from the transplantation algorithm. 
The functions names must be written in a text file: foo bar .

    * --transplant_log /path/to/folder/ :(optional parameter) → log the results of the transplantation operations, in every generation

    * --transplant_statistics /path/to/file:(optional parameter) → log statistics about the transplantation operation

    * --urandom_seeds → muScalpel will take its seeds from /dev/urandom

    * --random_seeds → muScalpel will take its seeds from /dev/random. This may take a while.

    * --seeds_file /path/to/file → take the seeds from a file. The file must contain 7 lines of 4 numbers each, as in this example.

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
Ex: --coreFunction write_archive --donorSystem mytar --donorFileTarget Transplant-mytar/Donor/append.c --hostFileTarget Transplant-mytar/Host/pidgin-2.10.9/libpurple/ft.c

--core_function function_name :(required parameter) → the entry point of the functionality to transplant.
--donorSystem:(required parameter) → the donor system name.
--donor_target /path/to/file :(required parameter) → the file in the donor, with the function annotated for transplantation.
--host_target /path/to/file :(required parameter) → the file in the host that contains the __ADDGRAFTHERE__JUSTHERE annotation. This annotation is required, and it marks the place where the organ will be added.

## Deployment

## Authors
 Created by Marginean Alexandru on 27/02/14 and evolved by Leandro Oliveira de Souza  on 15/05/2017

## License
 Copyright (c) 2014 Marginean Alexandru and 2017 Leandro Oliveira de Souza. All rights reserved.
