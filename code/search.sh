#!/bin/sh
# identifier search only, space not supported in string
# usage: findstring <string> *.cpp *.h
st="$1"
shift
for xt in $*
do
	a="find . -name "$xt" -print"
	findfile=`$a`
	for cfile in $findfile
	do
		cnts="grep -c $st $cfile"
		cnt=`$cnts`
		if [ $cnt -gt 0 ]
		then
			echo "--------------------------------- "
			printf "In file "
			echo "$cfile"
			cmd="grep -n $st $cfile"
			res=`$cmd`
			echo "$res"
		fi
	done
done
