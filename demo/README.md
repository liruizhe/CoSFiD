DEMO of CosFiD
===========================

The DEMO shows a example to detect the compilation-sensitive code file(s) of a program.

The program consists of 9 source code files. The function foo8() in foo8.c will return 2 rather than 1 when the macro **COSFID_DEMO** is defined.

Usage:

    CoSFiD "./build.sh" "./demo" "cmp" "gcc4.6.4" "-DHELLO" "-DCOSFID_DEMO" "demo.log"

The ***"gcc4.6.4"*** can be replaced with compiler in your system.

CoSFiD will find foo8.c is the compilation-sensitive code file.
