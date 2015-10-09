#!/bin/bash
rm -f *.o demo
for i in $(seq 1 8)
do
    gcc foo$i.c -c -DCoSFiD -o foo$i.o
done
gcc main.c -c -DCoSFiD -o main.o
gcc *.o -o demo
