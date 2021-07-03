#!/usr/bin/env bash

# This script will send time to the Arduino clock for display

# You may need to change the character device name associated
# with your Arduino, here it is /dev/ttyACM0

# Set the TTY parameters (the speed should match the one in the .ino code)
#stty -F ${PortName}  ${SerialSpeed}  raw -clocal -echo icrnl
stty -F /dev/ttyACM0  9600  raw -clocal -echo icrnl
#stty -F /dev/ttyACM1  9600  raw -clocal -echo icrnl

while true ;do
 # Specify the time zone
 TZ="US/Eastern" date +"%H%M"
 # or just dispaly the same time as the computer clock
 #date +"%H%M"
 sleep 1
done >> /dev/ttyACM0 #>> /dev/ttyACM1
