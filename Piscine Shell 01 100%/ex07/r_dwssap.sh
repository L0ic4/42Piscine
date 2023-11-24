#!/bin/sh

cat /etc/passwd | grep -o '^[^#]*' | sed -n 0~2p | awk -F ':' '{print $1}' | rev | sort -r | awk -v a="$FT_LINE1" -v b="$FT_LINE2" 'NR==a,NR==b' ORS=", " | sed 's/, $/./g' | tr -d '\n'
