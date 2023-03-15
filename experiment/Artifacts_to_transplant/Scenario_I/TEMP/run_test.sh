#!/bin/bash

ulimit -s 65353

rm -r -f FEATURE/*.o
cp -r -f test_suite.c FEATURE

make
rm -r -f *.o
