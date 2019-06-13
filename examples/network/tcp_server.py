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

s = usocket.socket(usocket.AF_INET,usocket.SOCK_STREAM)  # Create STREAM TCP socket
s.bind(('192.168.12.32', 6001))   
s.listen(5)
s.setblocking(True)
sock,addr=s.accept()              
sock.recv(10)                    
s.close()
