import serial

# Read and write to file
with open("index.html", 'w') as f:
	with serial.Serial('/dev/cu.usbmodem101', 9600, timeout=1) as ser:
		while True: # Infinite loop
			serial_input = ser.read(1)        # read up to ten bytes (timeout)
			if serial_input != b"":
				print(serial_input.decode("utf-8"), end="", flush=True) # Print to terminal
				f.write(serial_input.decode("utf-8")) # Write to file - decode




# Read only
# with serial.Serial('/dev/cu.usbmodem101', 9600, timeout=1) as ser:
# 	while True:
# 		s = ser.read(1)        # read up to ten bytes (timeout)
# 		if s != b"":
# 			print(s.decode("utf-8"), end="", flush=True)
