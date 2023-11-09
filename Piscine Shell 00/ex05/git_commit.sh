#!/bin/sh

commits=$(git log -5 | grep ^commit | cut -d " " -f 2)
echo $commits | tr ' ' '\n\$'
