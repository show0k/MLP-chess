#!/bin/bash   
echo 'Build GUI'
cd GUI/ && make

echo 'Build engine'
cd ../engine/ && make

echo 'Build done. Run ./run.sh to start the program'


