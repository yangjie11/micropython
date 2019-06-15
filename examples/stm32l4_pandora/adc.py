# 
# Copyright (c) 2006-2019, RT-Thread Development Team
# 
# SPDX-License-Identifier: MIT License
# 
# Change Logs:
# Date           Author       Notes
# 2019-06-13     SummerGift   first version
#

from machine import ADC     # 从 machine 导入 ADC 类

adc = ADC(2, 5)             # 创建 ADC 对象，当前使用编号为 2 的 ADC 设备的 5 通道
adc.read()                  # 获取 ADC 对象采样值
adc.deinit()                # 关闭 ADC 对象
adc.init(5)                 # 开启并重新配置 ADC 对象
