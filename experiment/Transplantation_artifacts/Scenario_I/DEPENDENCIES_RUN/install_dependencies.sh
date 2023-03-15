#!/bin/bash

SUCCESFUL=1
 echo '#!/bin/bash' > uninstall.sh
 echo '#Uninstalling dependences' >> uninstall.sh

installCommandLineDevTools(){
if xcode-select --install 2>&1 | grep installed; then
    echo command line tools already installed;
else
    echo command line developer tools not installed;
    echo installing command line tools;
    echo 'brew uninstall xcode-select' >> uninstall.sh
    SUCCESFUL=0
 fi
 }


 installHomeBrew(){
 if which brew > /dev/null; then
    echo Homebrew is installed
 else
    echo Homebrew is not installed.
    echo Installing Homebrew....
    ruby -e "$(curl -fsSL
    https://raw.githubusercontent.com/Homebrew/install/master/install)"
    echo 'brew uninstall Homebrew' >> uninstall.sh
    if which brew > /dev/null; then
        echo Homebrew is installed

    else
        echo "Homebrew is not installed!"
        SUCCESFUL=0
    fi
 fi
 }


 installAutoMake(){
 if which automake > /dev/null; then
    echo automake is installed
 else
    echo automake is not installed.
    echo Installing automake....
    echo brew install automake
    echo 'brew uninstall automake' >> uninstall.sh
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
 else
    echo autoconf is not installed.
    echo Installing autoconf....
    echo brew install autoconf
    echo 'brew uninstall autoconf' >> uninstall.sh
    if which autoconf > /dev/null; then
        echo autoconf is installed
    else
        echo "Erro trying to install Autoconf!"
        SUCCESFUL=0
    fi
 fi
 }
 
 installLibtool(){
 if which libtool > /dev/null; then
    echo libtool is installed
 else
    echo libtool is not installed.
    echo Installing libtool....
    echo brew install libtool
    echo 'brew uninstall libtool' >> uninstall.sh
    if which libtool > /dev/null; then
        echo libtool is installed
    else
        echo "Erro trying to install libtool!"
        SUCCESFUL=0
    fi
 fi
 }
 
installPkg-config(){
 if which pkg-config > /dev/null; then
    echo pkg-config is installed
 else
    echo pkg-config is not installed.
    echo Installing pkg-config....
    echo brew install pkg-config
    echo 'brew uninstall pkg-config' >> uninstall.sh
    if which pkg-config > /dev/null; then
        echo pkg-config is installed
    else
        echo "Erro trying to install pkg-config!"
        SUCCESFUL=0
    fi
 fi
 }
 
installCheck(){
 if which check > /dev/null; then
    echo check is installed
 else
    echo check is not installed.
    echo Installing check....
    echo brew install check
    echo 'brew uninstall check' >> uninstall.sh
    if which check > /dev/null; then
        echo check is installed
    else
        echo "Erro trying to install check!"
        SUCCESFUL=0
    fi
 fi
 }
 
 installGlib(){
 if which glib > /dev/null; then
    echo glib is installed
 else
    echo glib is not installed.
    echo Installing glib....
    echo brew install glib
    echo 'brew uninstall glib' >> uninstall.sh
    if which glib > /dev/null; then
        echo glib is installed
    else
        echo "Erro trying to install glib!"
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


