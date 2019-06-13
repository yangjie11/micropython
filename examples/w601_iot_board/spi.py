/*
 * Copyright (c) 2006-2019, RT-Thread Development Team
 *
 * SPDX-License-Identifier: MIT License
 *
 * Change Logs:
 * Date           Author       Notes
 * 2019-06-13     SummerGift   first version
 */

from machine import Pin, SPI

clk = Pin(("clk", 43), Pin.OUT_PP)
mosi = Pin(("mosi", 44), Pin.OUT_PP)
miso = Pin(("miso", 45), Pin.IN)
spi = SPI(-1, 500000, polarity = 0, phase = 0, bits = 8, firstbit = 0, sck = clk, mosi = mosi, miso = miso)
print(spi)
spi.write("hello rt-thread!")
spi.read(10)
