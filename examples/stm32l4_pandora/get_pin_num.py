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
        print("ERROR : Please pass in the correct parameters P + <A~K> + number, such as PE11")
        return

    if not pin_index[1].isupper():
        print("ERROR : Please pass in the correct parameters P + <A~K> + number, such as PE11")
        return

    return (ord(pin_index[1]) - ord('A')) * 16 + int(pin_index[2:])

print(get_pin_num("PE11")) # Get the pin number for PE11
