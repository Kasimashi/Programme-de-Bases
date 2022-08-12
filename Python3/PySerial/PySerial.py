#!/usr/bin/env python
import serial
import time
import thread


class MSerialPort:
    message = ''

    def __init__(self, port, buand):
        self.port = serial.Serial(port, buand)
        if not self.port.isOpen():
            self.port.open()

    def port_open(self):
        if not self.port.isOpen():
            self.port.open()

    def port_close(self):
        self.port.close()

    def send_data(self, data):
        number = self.port.write(data)
        return number

    def read_data(self):
        while True:
            data = self.port.readline()
            self.message += data


if __name__ == '__main__':
    mSerial = MSerialPort('COM5', 115200)
    thread.start_new_thread(mSerial.read_data, ())
    while True:
        time.sleep(1)
        print mSerial.message
        print 'next line'