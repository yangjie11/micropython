# 
# Copyright (c) 2006-2019, RT-Thread Development Team
# 
# SPDX-License-Identifier: MIT License
# 
# Change Logs:
# Date           Author       Notes
# 2019-06-13     SummerGift   first version
#

import uos

uos.mkdir("rtthread")
uos.getcwd()
uos.chdir("rtthread")
uos.getcwd()
uos.listdir()
uos.rmdir("11")
uos.listdir()
