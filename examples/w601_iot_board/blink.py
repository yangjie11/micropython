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
led = Pin(("X1", 38), Pin.OUT_PP)        #create led object from pin 38, Set pin 38 to output mode

while True:
    led.value(0)            #Set led turn on
    time.sleep(0.5)
    led.value(1)            #Set led turn off
    time.sleep(0.5)
