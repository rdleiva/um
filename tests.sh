#!/bin/sh

for i in /csc/411/um/midmark.um /csc/411/um/sandmark.umz
do
	time -f "um $i: %e seconds" ./um $i > /dev/null
done
