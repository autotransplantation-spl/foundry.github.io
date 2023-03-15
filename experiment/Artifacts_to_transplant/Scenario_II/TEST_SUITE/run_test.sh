#!/bin/bash

ulimit -s 65353


cp -r -f test_suite.c FEATURE
cp -r -f InterfaceWithCoreFeature.c FEATURE
cp -r -f InterfaceHeader.h FEATURE
cd ..
cp -r -f HOST_TO-TRANSPLANT/NEATVI_1.0/* TEST_SUITE/FEATURE
cd TEST_SUITE
rm -r -f FEATURE/*.o
make
rm -r -f *.o
