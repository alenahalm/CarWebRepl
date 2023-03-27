from machine import UART
import os


class MiniCar:
  def __init__(self):
    self.uart = UART(0, 115200)
    self.uart.init(115200, bits=8, parity=None, stop=1)
    os.dupterm(None, 1)

  def forward(self):
    self.uart.write('f')

  def backward(self):
    self.uart.write('b')

  def stop(self):
    self.uart.write('s')

  def turn_left(self):
    self.uart.write('l')

  def turn_right(self):
    self.uart.write('r')
Footer