/*
 * Copyright (c) 2006-2019, RT-Thread Development Team
 *
 * SPDX-License-Identifier: MIT License
 *
 * Change Logs:
 * Date           Author       Notes
 * 2019-06-13     SummerGift   first version
 */

from machine import Pin

p_out = Pin(("X1", 33), Pin.OUT_PP)
p_out.value(1)              # set io high
p_out.value(0)              # set io low

p_in = Pin(("X2", 32), Pin.IN, Pin.PULL_UP)
p_in.value()                # get value, 0 or 1
