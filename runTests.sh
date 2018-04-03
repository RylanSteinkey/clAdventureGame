#!/bin/bash
# ^ is called bash bang ... - tells what program to run the script 
# can use py / c++ 
#tells the os to invoke the specified shell to 
#run that script 
FNAME=$(date +%y%m%d) 
TO="/home/ster2720/YaDimSum"
cd "/home/ster2720/YaDimSum" #wherever.., duefault is the same to 

ulimit -t 10
#this is very particular about the spaces
#true is 0 and false is 1
if [ $# -eq 2 ] 
then
    TO="$1"
    FROM="$2"
elif [ $# -eq 1 ] 
then
    TO="$1"
fi


echo "Pulling Git Repository"
git pull  

if [ $? -eq 0 ]
then
    cd "/home/ster2720/YaDimSum/cc_files"
    make clean-all
    make -k > "/home/ster2720/YaDimSum/test_results/$FNAME.comp.$$" 2>&1
    if [ $? -eq 0 ]
    then
	./addedByScript > "/home/ster2720/YaDimSum/test_results/$FNAME.res.$$"
    fi 
    cd -
git add *
git commit -m "automated"
git push

fi
