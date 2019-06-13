/*
 * Copyright (c) 2006-2019, RT-Thread Development Team
 *
 * SPDX-License-Identifier: MIT License
 *
 * Change Logs:
 * Date           Author       Notes
 * 2019-06-13     SummerGift   first version
 */

import usocket

s = usocket.socket(usocket.AF_INET,usocket.SOCK_STREAM)
s.connect(("192.168.10.110",6000))  
s.send("micropython")               
s.close()
