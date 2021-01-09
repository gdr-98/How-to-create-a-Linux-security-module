# How-to-create-a-Linux-security-module

This repository aims to show how to create a Linux Security Module for the versions 4.x / 5.x of the Linux Kernel.

It is recommended to use a clear kernel to avoid print or file problems. 

The creation of a module requires the enabling in the kernel security options, so:
1) make menuconfig in the kernel folder.
2) Search for the security options.
3) Mark our module (it has the description we added in the Kconfig file). 
4) Compile and run the kernel.
