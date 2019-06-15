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

print("获得当前所在目录：")
print(uos.getcwd())

print("创建文件夹 ：rtthread")
uos.mkdir("rtthread")

print("列出当前目录下的文件列表：")
print(uos.listdir())

print("移动当前目录到 rtthread 文件夹下：")
uos.chdir("rtthread")

print("获得当前所在目录：")
print(uos.getcwd())

print("切换到上一级目录：")
uos.chdir("..")

print("获得当前所在目录：")
print(uos.getcwd())

print("列出当前目录下的文件列表：")
print(uos.listdir())

print("删除 rtthread 文件夹：")
uos.rmdir("rtthread")

print("列出当前目录下的文件列表：")
print(uos.listdir())
