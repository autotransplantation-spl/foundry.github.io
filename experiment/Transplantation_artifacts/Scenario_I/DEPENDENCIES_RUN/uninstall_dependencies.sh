#!/bin/bash

SUCCESFUL=1
 echo '#!/bin/bash' > uninstall.sh
 echo '#Uninstalling dependences'

installCommandLineDevTools(){
if xcode-select --install 2>&1 | grep installed; then
    echo command line tools already installed;
    echo uninstalling command line tools;
    echo brew uninstall xcode-select
    SUCCESFUL=0
 fi
 }


 installAutoMake(){
 if which automake > /dev/null; then
    echo automake is installed
    echo brew uninstall automake
    if which automake > /dev/null; then
        echo automake is installed
    else
        echo "Automake is not installed!"
        SUCCESFUL=0
    fi
 fi
 }
 
 installAutoConf(){
 if which autoconf > /dev/null; then
    echo autoconf is installed
    echo brew uninstall autoconf
    if which autoconf > /dev/null; then
        echo "Erro trying to uninstall Autoconf!"
    else
        echo autoconf is not installed
        SUCCESFUL=0
    fi
 fi
 }
 
 installLibtool(){
 if which libtool > /dev/null; then
    echo libtool is installed
    echo uninstalling libtool....
    echo brew uninstall libtool
    if which libtool > /dev/null; then
        echo "Erro trying to uninstall libtool!"
    else
        echo libtool is not installed 
        SUCCESFUL=0
    fi
 fi
 }
 
installPkg-config(){
 if which pkg-config > /dev/null; then
    echo pkg-config is installed
    echo uninstalling pkg-config....
    echo brew uninstall pkg-config
    if which pkg-config > /dev/null; then
        echo "Erro trying to uninstall pkg-config!"
    else
        echo pkg-config is not installed 
        SUCCESFUL=0
    fi
 fi
 }
 
installCheck(){
 if which check > /dev/null; then
    echo check is installed
    echo uninstalling check....
    echo brew install check
    echo brew uninstall check
    if which check > /dev/null; then
        echo "Erro trying to uninstall check!"
    else
        echo  check is not installed
        SUCCESFUL=0
    fi
 fi
 }
 
 installGlib(){
 if which glib > /dev/null; then
    echo glib is installed

    echo Uninstalling glib....
    echo brew uninstall glib
    if which glib > /dev/null; then
        echo "Erro trying to uninstall glib!" 
    else
        echo glib is installed
        SUCCESFUL=0
    fi
 fi
 }
 
#Invoke your functions
installCommandLineDevTools
installHomeBrew
installAutoMake
installAutoConf
installLibtool
installPkg-config
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


