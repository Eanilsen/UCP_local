#!/bin/bash

IN_FILE=$1
PERMISSION="`stat -c "%a" ${IN_FILE}`"

if [[ ${PERMISSION} == "7[0-9][0-9]$" ]]; then
    echo "test"
fi
