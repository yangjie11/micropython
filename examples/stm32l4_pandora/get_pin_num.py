# 
# Copyright (c) 2006-2019, RT-Thread Development Team
# 
# SPDX-License-Identifier: MIT License
# 
# Change Logs:
# Date           Author       Notes
# 2019-06-28     SummerGift   first version
#

def get_pin_num(pin_index):
    """
    Get the GPIO pin number through the GPIO index, format must be "P + <A~K> + number", such as PE11
    """

    if pin_index[0] != 'P':
        print("ERROR : Please pass in the correct parameters")
        return

    if pin_index[1] == 'A':
        pin_num = pin_index[2:]
    elif pin_index[1] == 'B':
        pin_num = (16 + int(pin_index[2:]))
    elif pin_index[1] == 'C':
        pin_num = (32 + int(pin_index[2:]))
    elif pin_index[1] == 'D':
        pin_num = (48 + int(pin_index[2:]))
    elif pin_index[1] == 'E':
        pin_num = (64 + int(pin_index[2:]))
    elif pin_index[1] == 'F':
        pin_num = (80 + int(pin_index[2:]))
    elif pin_index[1] == 'G':
        pin_num = (96 + int(pin_index[2:]))
    elif pin_index[1] == 'H':
        pin_num = (112 + int(pin_index[2:]))
    elif pin_index[1] == 'I':
        pin_num = (128 + int(pin_index[2:]))
    elif pin_index[1] == 'J':
        pin_num = (144 + int(pin_index[2:]))
    elif pin_index[1] == 'K':
        pin_num = (160 + int(pin_index[2:]))

    return pin_num

pin_num = get_pin_num("PE11")   # Get the pin number for PE11
print(pin_num)
