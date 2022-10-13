import serial

with open("index.html", 'w') as f:
	with serial.Serial('/dev/cu.usbmodem1101', 9600, timeout=1) as ser:
		while True:
			s = ser.read(1)        # read up to ten bytes (timeout)
			if s != b"":
				print(s.decode("utf-8"), end="", flush=True)
				f.write(s.decode("utf-8"))

# with serial.Serial('/dev/cu.usbmodem101', 9600, timeout=1) as ser:
# 	while True:
# 		s = ser.read(1)        # read up to ten bytes (timeout)
# 		if s != b"":
# 			print(s.decode("utf-8"), end="", flush=True)
