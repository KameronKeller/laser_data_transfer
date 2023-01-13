# laser_data_transfer
Transmit and receive data over laser with a pair of Arduinos. 

Co-Author: [Colin Suckow](https://github.com/Colin-Suckow)

## Arduino Instructions
See the laserdatatransfer_presentation.pdf for a basic diagram of the Arduino setup.

Copy the laser/laser.ino file to the first Arduino. In the Arduino IDE, open the serial monitor and type the message you wish to send.

Copy the photodiode/photodiode.ino to the second Arduino. In the Arduino IDE, open the serial monitor to view the messages received by the laser.

Ensure the laser is pointed at the photodiode, and have fun sending messages via laser!

## Python Instructions

If you wish to save the input of the receiving Arduino to a file, follow these instructions.
```
python3 -m venv venv
source venv/bin/activate
pip3 install pyserial
```
Open `python_logging/log_comms.py` and set the `SERIAL_PORT` and `BAUD` variables to your Arduino. Then run the following to save the input from the laser to the file specified in the `FILENAME` variable.
```
python3 python_logging/log_comms.py
```
