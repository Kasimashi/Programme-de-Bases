from gpiozero import LED
from gpiozero.pins.pigpio import PiGPIOFactory
from time import sleep

factory3 = PiGPIOFactory(host='192.168.1.17')
led_green = LED(pin=26, pin_factory=factory3)
led_red = LED(pin=19, pin_factory=factory3)
led_blue = LED(pin=13, pin_factory=factory3)

while True:
    led_green.on()
    led_red.on()
    led_blue.on()
    sleep(1)
    led_green.off()
    led_red.off()
    led_blue.off()
    sleep(1)
