# 
# Copyright (c) 2006-2019, RT-Thread Development Team
# 
# SPDX-License-Identifier: MIT License
# 
# Change Logs:
# Date           Author       Notes
# 2019-06-13     SummerGift   first version
#

import random

for j in range(0, 2):
    random.seed(13)  # 指定随机数种子
    for i in range(0, 10):  # 生成0到10范围内的随机序列
        print(random.randint(1, 10))
    print("end")
