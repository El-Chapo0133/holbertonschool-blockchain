#!/bin/sh
#
#     Filename: install.bash
#
#  Description: Install all the deps for the blockchain project
#
#      Version: 1
#      Created: 25.05.2025
# 
#       Author: Loris Levêque (9601)
# Organization: Holberton
#
# ========================================================================

# sudo permission required
if [ "$(id -u)" != "0" ]
then
	>&2 echo "Must be executed as root"
	exit 1
fi

# llist lib given by holberton (required)
bash llist/install.bash

# openssl lib (required)
apt install libssl-dev
# if this doesn't work you have to clone and make the github repo
# check libssl-dev package
echo "libssl-dev installed version"
# apt-cache policy libssl-dev | grep "Installed"
dpkg -l libssl-dev
echo "openssl installed version"
openssl version

