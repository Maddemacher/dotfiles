#!/usr/bin/env bash
set -e
set -o pipefail

QMK="$HOME/git/qmk_firmware"

if [ ! -d "$QMK" ] ; then
    cd "$HOME/git" && git clone https://github.com/qmk/qmk_firmware
fi

create_symlinks() {
    FROM="$HOME/git/dotfiles/ergodox/$1"
    TO="$QMK/keyboards/$1/keymaps/maddemacher"
    mkdir -p "$TO"

    echo "--> Symlinking $1"
    ln -sf "$FROM/keymap.c" "$TO/keymap.c"
    ln -sf "$FROM/rules.mk" "$TO/rules.mk"
    
    if [ -f "$FROM/config.h"  ] ; then
        ln -sf "$FROM/config.h" "$TO/config.h"
    fi
}

create_symlinks ergodox_ez
