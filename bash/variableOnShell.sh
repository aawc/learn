#!/bin/bash

# Try running:
# ./variableOnShell.sh
# AND
# A_V=2 ./variableOnShell.sh

A_V="${A_V:-1}"
echo $A_V
