#!/usr/bin/env bash

xrandr --output eDP1 --mode 3840x2160 --output HDMI1 --mode 1920x1080 --scale 2x2 --same-as eDP1
xrandr --output HDMI1 --mode 1920x1080 --same-as eDP1 --panning 1920x1080
xrandr --output HDMI1 --off
xrandr --output eDP1 --mode 3840x2160 --output HDMI1 --mode 1920x1080 --scale 2x2 --same-as eDP1
