

import serial

try:
    ser = serial.Serial("/dev/cu.usbmodem101", 9600, timeout=0.5)
    print("connected!", ser.portstr)
except serial.SerialException:
    print("Not Connected!")
    pass

# if classes[index] == 'pneu':
#     ser.write(b'1')


ser.close()
print("closed connection!")