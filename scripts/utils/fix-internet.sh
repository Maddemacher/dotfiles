#!/usr/bin/env bash

echo "1" > /sys/bus/pci/devices/0000\:02\:00.0/remove
sleep 3
echo "1" > /sys/bus/pci/rescan
 
