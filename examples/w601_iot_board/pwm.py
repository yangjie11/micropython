/*
 * Copyright (c) 2006-2019, RT-Thread Development Team
 *
 * SPDX-License-Identifier: MIT License
 *
 * Change Logs:
 * Date           Author       Notes
 * 2019-06-13     SummerGift   first version
 */

from machine import PWM     # 从 machine 导入 PWM 类

pwm = PWM(1, 4, 1000, 100)  # 创建 PWM 对象，当前使用编号为 1 的 PWM 设备的 4 通道，初始化的频率为 1000Hz，占空比数值为 100（占空比为 100/255 = 39.22%）
pwm.freq(2000)              # 设置 PWM 对象频率
pwm.freq()                  # 获取 PWM 对象频率
pwm.duty(200)               # 设置 PWM 对象占空比数值
pwm.duty()                  # 获取 PWM 对象占空比数值
pwm.deinit()                # 关闭 PWM 对象
pwm.init(4, 1000, 100)      # 开启并重新配置 PWM 对象