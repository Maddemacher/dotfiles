#!/usr/bin/env bash

set -e
set -o pipefail

cd "$HOME/git/qmk_firmware"
make ergodox_ez:maddemacher
