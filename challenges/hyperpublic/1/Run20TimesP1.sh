#!/bin/bash
for ((i=0; i<20; i++)); do p1 < p1.txt | sort -nr | head -n 3 | tr -d '
'; done;
