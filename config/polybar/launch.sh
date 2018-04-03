#!/usr/bin/env sh
# Terminate already running bar instances
killall polybar

# Wait until the processes have been shut down
while pgrep -x polybar >/dev/null; do sleep 1; done

# Launch bars
MONITOR=eDP1 polybar -r top &
MONITOR=HDMI1 polybar -r top &
