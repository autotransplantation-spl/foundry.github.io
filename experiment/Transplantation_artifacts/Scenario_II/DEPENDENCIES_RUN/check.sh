#!/bin/bash

SUCCESFUL=1
 echo '#Dependences are missing' >> dependencies_log.sh

installCommandLineDevTools(){
if xcode-select --install 2>&1 | grep installed; then
    echo command line tools already installed;
else
    echo '#xcode-select' >> dependencies_log.txt
    SUCCESFUL=0
 fi
 }

 installAutoMake(){
 if which automake > /dev/null; then
    echo automake is installed
 else
    echo "Automake is not installed!"
    echo 'automake' >> dependencies_log.txt
    SUCCESFUL=0
 fi
 }
 
 installAutoConf(){
 if which autoconf > /dev/null; then
    echo autoconf is installed
 else
    echo autoconf is not installed.
    echo 'autoconf' >> dependencies_log.txt
    SUCCESFUL=0 
 fi
 }
 
 installLibtool(){
 if which libtool > /dev/null; then
    echo libtool is installed
 else
    echo libtool is not installed.
    echo 'libtool' >> dependencies_log.txt
    SUCCESFUL=0
 fi
 }
 
installPkg-config(){
 if which pkg-config > /dev/null; then
    echo pkg-config is installed
 else
    echo pkg-config is not installed.
    echo 'pkg-config' >> dependencies_log.txt
    SUCCESFUL=0
 fi
 }
 
 installTexinfo(){
 if which texinfo > /dev/null; then
    echo texinfo is installed
 else
    echo texinfo is not installed.
    echo 'texinfo' >> dependencies_log.txt
    SUCCESFUL=0
 fi
 }
 
installCheck(){
 if which check > /dev/null; then
    echo check is installed
 else
    echo check is not installed.
    echo 'check' >> dependencies_log.txt
    SUCCESFUL=0
 fi
 }
 
 installGlib(){
 if which glib > /dev/null; then
    echo glib is installed
 else
    echo glib is not installed.
    echo 'glib' >> dependencies_log.txt
    SUCCESFUL=0
 fi
 }
 
#Invoke your functions
installCommandLineDevTools
installHomeBrew
installAutoMake
installAutoConf
installLibtool
installPkg-config
installTexinfo
installCheck
installGlib
 
#echo $SUCCESFUL
exit $SUCCESFUL



#libglib2.0-dev
#dpkg -s make
#dpkg -s cflow
#dpkg -s pkg-config
#dpkg -s gcc-4.8
#dpkg -s libgcrypt20


