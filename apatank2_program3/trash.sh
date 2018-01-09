#!/bin/bash
LIST=$@
DIRNAME="TRASH"
if [ ! -d "$DIRNAME" ]
then
	mkdir $DIRNAME
	echo "Directory Successfully Created"
fi
for FILE in $LIST
do
if [ -f $FILE ]
then
	if [ $FILE != "hidden.o" ]
	then 
	mv $FILE $DIRNAME
	echo "File" $FILE  "Successfully moved to TRASH Directory"
	fi
else
	echo $FILE "File Does Not Exist"
fi
done
find "TRASH" ! -type d -mmin +60 ! -name 'hidden.o' ! -name 'makefile' ! -name 'trash.sh' ! -name 'defuseTheBomb' ! -name "program3B.c"
	echo "Sript Completed" 
