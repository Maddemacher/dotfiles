#!/usr/bin/env bash

set -e
set -o pipefail

CURR=`pwd`

mkdir -p ./output

cd "$HOME/git/qmk_firmware"
make ergodox_ez:maddemacher

cp ergodox_ez_maddemacher.hex $CURR/


