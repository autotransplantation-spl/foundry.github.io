#!/bin/bash

cd ..
cp -r -f Makefile NEATVI
cd NEATVI

make clean
make

./vi TEXT.txt
i
FILE.in
[ESC] :wa
 


