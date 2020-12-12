# Arduino clock display for Linux
A simple clock using TM1637 4 digits display and Arduino attached to a Linux computer.
The BASH script uses `date` to report the current time (in the user-specified time zone) 
to Arduino via the USB (Serial) port. Arduino uses the TM1637 4 digits display (via I2C) 
to display the time.
