#!/bin/bash
shopt -s extglob
cp -a !(debian|HDF$1) HDF$1
cp -a HDF$1 HDF4_ALT
