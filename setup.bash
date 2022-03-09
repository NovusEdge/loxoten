#!/usr/bin/env bash


echo "Fetching from remote repository branch";

git fetch origin linux

echo "Using CMake for building binaries..."
make
