# 
# Copyright (c) 2006-2019, RT-Thread Development Team
# 
# SPDX-License-Identifier: MIT License
# 
# Change Logs:
# Date           Author       Notes
# 2019-06-13     SummerGift   first version
#

import utime as time
from machine import Pin

PIN_LED_R = 38
PIN_LED_G = 39
PIN_LED_B = 40

LED_ON  = 0
LED_OFF = 1

led_r = Pin(("LED RED", PIN_LED_R), Pin.OUT_PP) 
led_g = Pin(("LED GREEN", PIN_LED_G), Pin.OUT_PP) 
led_b = Pin(("LED BLUE", PIN_LED_B), Pin.OUT_PP) 

blink_tab = [(LED_ON,LED_ON,LED_ON),
             (LED_OFF,LED_ON,LED_ON),
             (LED_ON,LED_OFF,LED_ON),
             (LED_ON,LED_ON,LED_OFF),          
             (LED_OFF,LED_OFF,LED_ON),
             (LED_ON,LED_OFF,LED_OFF),
             (LED_OFF,LED_ON,LED_OFF),
             (LED_ON,LED_OFF,LED_OFF)]


while True:
    led.value(0)            #Set led turn on
    time.sleep(0.5)
    led.value(1)            #Set led turn off
    time.sleep(0.5)
