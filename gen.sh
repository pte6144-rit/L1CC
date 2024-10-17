#!/usr/bin/bash

killall havoc 2>/dev/null

taskset -c 0 ./havoc &
sleep 1
taskset -c 4 ./threaded_spy

killall havoc

tail -n 200 dat.txt > short_dat.txt

./parse_lats.py short_dat.txt
