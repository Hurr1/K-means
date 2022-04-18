#!/bin/bash
DIR="/out/build/"
if [ ! -d "$DIR" ]; then
  mkdir -p out/build/
fi
cd out/build/ && cmake -S ../../ -B . && make && cd ../../

if [[ -f ./K-Means ]]; then
 echo "Succes build"
else
 echo "Fail"
fi
