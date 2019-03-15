#!/bin/bash
cp -f libtermb.so /usr/lib/libtermb.so
gcc -o test test.c -L./ -ltermb