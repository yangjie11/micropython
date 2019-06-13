/*
 * Copyright (c) 2006-2019, RT-Thread Development Team
 *
 * SPDX-License-Identifier: MIT License
 *
 * Change Logs:
 * Date           Author       Notes
 * 2019-06-13     SummerGift   first version
 */

from machine import RTC

rtc = RTC()                        # 创建 RTC 设备对象
rtc.init((2019,6,5,2,10,22,30,0))  # 设置初始化时间
rtc.now()                          # 获取当前时间
rtc.deinit()                       # 重置时间到2015年1月1日
rtc.now()                          # 获取当前时间
