#!/bin/bash

if [ -z "$1" ]; then
    echo "[ERROR] using: $0 <SCR_DIR>"
    exit 1
fi

DIR="$1"

echo "Clean build"
make clean

echo "[INFO] Start build. target DIR: $DIR"
make DIR="$DIR"

if [ $? -ne 0 ]; then
    echo "[ERROR] COMPILE FIAL"
    exit 1
fi

if [ -x build/app ]; then
    echo "[INFO] EXEC: build/app"
    echo ""
    ./build/app
else
    echo "[ERROR] EXEC: 'build/app' is not exist"
    exit 1
fi
