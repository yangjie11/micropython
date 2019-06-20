# 
# Copyright (c) 2006-2019, RT-Thread Development Team
# 
# SPDX-License-Identifier: MIT License
# 
# Change Logs:
# Date           Author       Notes
# 2019-06-13     SummerGift   first version
#

from machine import ADC     # Import the ADC class from machine

adc = ADC(2, 5)             # Creates an ADC object that currently uses the 5 channels of an ADC device numbered 2
adc.read()                  # Gets the ADC object sampling value
adc.deinit()                # Close ADC object
adc.init(5)                 # Open and reconfigure the ADC object
