# VSCode 最好用的 MicroPython 插件

VSCode 最好用的 MicroPython 插件，为 MicroPython 开发提供了强大的开发环境，主要特性如下：

- 便捷的开发板连接方式（串口、网络、USB）
- 支持基于 MicroPython 的代码智能补全与语法检查
- 支持 MicroPython REPL 交互环境
- 提供丰富的代码示例与 demo 程序
- 支持全工程同步功能
- 支持在设备上运行示例代码文件
- 支持代码片段运行功能
- 支持多款主流 MicroPython 开发板
- 支持 windows 及 ubuntu 操作系统

## 开发板支持列表

| 编号 | 开发板名称                                                   | 固件获取方式                                                 |
| ---- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| 1    | [潘多拉 IoT Board 物联网开发板 STM32L475](https://item.taobao.com/item.htm?spm=a1z10.5-c-s.w4002-18400369818.12.2ba47ea5PzJxZx&id=583843059625) | [RT-Thread 论坛固件汇总贴](https://www.rt-thread.org/qa/forum.php?mod=viewthread&tid=12305&page=1&extra=#pid52954) |
| 2    | [正点原子 W601 WIFI 物联网开发板](https://item.taobao.com/item.htm?spm=a230r.1.14.13.7c5b4a9bS2LYUD&id=602233847745&ns=1&abbucket=17#detail) | [RT-Thread 论坛固件汇总贴 ](https://www.rt-thread.org/qa/forum.php?mod=viewthread&tid=12305&page=1&extra=#pid52954) |
| 3    | [正点原子探索者 STM32F407 开发板](https://item.taobao.com/item.htm?spm=a1z10.5-c-s.w4002-18400369818.18.569779dc0A3gkT&id=41855882779) | [RT-Thread 论坛固件汇总贴](https://www.rt-thread.org/qa/forum.php?mod=viewthread&tid=12305&page=1&extra=#pid52954) |
| 4    | [ESP8266](http://docs.micropython.org/en/latest/esp8266/quickref.html) | [官方下载链接](https://micropython.org/download#esp8266)     |
| 5    | [ESP32](http://docs.micropython.org/en/latest/esp32/quickref.html) | [官方下载链接](https://micropython.org/download#esp32)       |
| 6    | [PYboard](http://docs.micropython.org/en/latest/pyboard/quickref.html) | [官方下载链接](https://micropython.org/download#pyboard)     |
| 7    | [others](https://micropython.org/download#other)             | [官方下载链接](https://micropython.org/download#other)       |

编号为 1、2、3 的开发板的固件由 RT-Thread 官方提供，同时针对 MicroPython 插件开发环境进行 **深度优化** ，提供强大的工程同步功能以及更加丰富的固件功能。

欢迎加入`RT-Thread MicroPython` 交流 QQ 群 **703840633** 获取最新固件，进行技术交流。

## 准备工作

1. 在 windows 操作系统下使用插件需要将 vscode 的默认终端修改为 powershell，如下图所示：

   ![select_powershell](assets/select_powershell.gif)

如果想要使用 MicroPython 自动补全功能（如果暂时不需要自动补全功能，可以跳过后续步骤），还需要进行如下操作：

2. 安装 Python 插件

3. 按照 Python 插件的提示在 PC 上安装 Python3 并加入到系统环境变量中

   ![Python plug](assets/install_python_plug.png)

如果在 PC 上已经安装过上述插件和程序，可以跳过此准备步骤。

### ubuntu 支持

本插件支持在 **ubuntu 18.04** 版本下运行，为了避免在 ubuntu 系统下频繁获取串口权限，需要将当前用户加入到 `dialout` 用户组中，手动输入如下命令即可，`$USERNAME` 是系统当前用户名：

`sudo usermod -aG dialout $USERNAME`

注意：配置修改后需要 **重启一下操作系统** 使配置生效。

## 快速上手

###  创建 MicroPython 工程

MicroPython 开发的第一步是创建 MicroPython 工程，后续所有操作都必须在工程内才能运行。创建一个新的 MicroPython 工程有两种方式，分别是创建一个空白工程和基于 Demo 创建工程，下面展示这两种方式。

#### 创建一个空白 MicroPython 工程

![create_blank_dir](assets/create_blank_prj.gif)

#### 创建一个基于 Demo 的 MicroPython 工程

通过该功能可以创建一个基于 demo 的 MicroPython 工程，开发者可以直接运行该 Demo 工程或者在该 Demo 的基础上实现自己想要的功能。

![create_demo_dir](assets/create_demo_prj.gif)

#### Weather Show Demo 在开发板上的运行效果

![demo_express](assets/demo_express.png)

该 Demo 全部代码使用 MicroPython 编写，可以同时在 [潘多拉 IoT Board 开发板](https://item.taobao.com/item.htm?spm=a1z10.5-c-s.w4002-18400369818.12.2ba47ea5PzJxZx&id=583843059625) 和 [正点原子 W601 WIFI 物联网开发板](https://item.taobao.com/item.htm?spm=a230r.1.14.13.7c5b4a9bS2LYUD&id=602233847745&ns=1&abbucket=17#detail) 上直接下载运行。

### 连接开发板

点击左下角的连接按钮，然后在弹出的设备列表中选择想要连接的设备，即可连接 MicroPython 开发板。

![uart_connect](assets/uart_connect.gif)

### 查看示例代码文件

MicroPython 插件提供丰富的示例代码，可在左侧活动栏中查看示例代码和库文件。

![example_code](assets/check_example.png)

### 在设备上运行 MicroPython 文件

开发板连接成功后，在示例代码文件上单击右键，在菜单中选择 `下载并在设备上运行该 MicroPython 文件 `，即可将示例文件下载到开发板中并运行，如下图所示：

![run_example](assets/run_example.gif)

### 在开发板上运行 MicroPython 代码片段

如果只是想进行代码量不大的代码调试，而不想将文件下载到开发板上，那么可以使用 **代码片段** 功能。在编辑器中选中想要运行的代码片段，然后在右键下拉菜单中选择 `在设备上执行选中的 MicroPython 代码` 选项，即可在 REPL 环境中运行所选代码。

![run_code_snippet](assets/run_code_snippet.gif)

### 基于 MicroPython 的代码智能补全

本插件支持基于 MicroPython 语法的代码智能补全和语法检查，这一强大功能对编写 MicroPython 代码十分友好。开发者可以在编写代码的同时查看 API 参数提示，同时醒目的错误提示也会让开发者更易于查找代码错误。

![auto_complete](assets/auto_complete.gif)

## 开发资源

- [RT-Thread MicroPython 开发用户手册](https://www.rt-thread.org/document/site/submodules/micropython/docs/)
- [RT-Thread MicroPython 软件包](https://github.com/RT-Thread-packages/micropython)
- [RT-Thread MicroPython 示例程序及库](https://github.com/RT-Thread/mpy-snippets)
- [RT-Thread MicroPython 论坛](https://www.rt-thread.org/qa/forum.php?mod=forumdisplay&fid=2&filter=typeid&typeid=20)
- [MicroPython IDE 用户指南](https://www.rt-thread.org/document/site/submodules/micropython/docs/MicroPythonPlug-in/MicroPython_IDE_User_Manual/)
- [MicroPython 固件开发指南](https://www.rt-thread.org/document/site/submodules/micropython/docs/MicroPythonPlug-in/MicroPython_Firmware_Development_Guide/)

## 注意事项

- 不要删除工程目录下的 `.mpyproject.json` 文件，该文件是 MicroPython 工程的配置文件，删除后将无法正常运行 MicroPython 代码程序。

  