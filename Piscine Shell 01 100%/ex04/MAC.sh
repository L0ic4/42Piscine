#!/bin/sh

ifconfig | grep -oP '([0-9A-Fa-f]{2}:){5}[0-9A-Fa-f]{2}'

