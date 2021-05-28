## FaOSK操作系统内核
***[English Edition (英文版)](./README.md)***

FaOSK操作系统内核是一个运行在intel x86平台的32位处理器上的的系统内核，可运行在qemu，bochs，virtualbox，vmware等虚拟机中，也可以在物理机上面运行。

### 系统功能列表
目前的FaOSK内核仍在开发中，功能非常之少，目前才做到中断，但这个内核仍然会继续更新。
这个内核非常适合给初学操作系统的人用于学习用途，它的代码注释极多，只要旁边在有一本操作系统的书籍，看懂它的的源代码基本上没有任何问题。

### 开发环境搭建

##### 1.克隆源代码：

使用gitee源：

```
git clone https://gitee.com/FirstArchve/FaOSK.git
```
使用github源：

```
git clone https://github.com/FirstArchve/FaOSK.git
```
##### 2.安装工具包

Debian/ubuntu/kill:

```
sudo apt-get install gcc nasm qemu qemu-system-x86
```
Red hat/Fedora/CentOS:

```
sudo yum install gcc nasm qemu qemu-system-x86
```
##### 3.其他编译环境准备

建立一个文件夹，用于挂载软盘映像并写入系统文件（详情见Makefile)。

```
sudo mkdir mnt
```
### 开发时所用命令

编译全部源代码：

```
make
```
在qemu中运行(需要先编译将新的系统文件写入软盘映像）：

```
make run
```
在bochs中运行(需要先安装bochs并先编译将新的系统文件写入软盘映像）：

```
make bochs
```
清理无用的过程文件：

```
make clean
```
以上为开发中常用命令，其余命令请参见Makefile。

### 项目结构

```
FaOSK
|
\___faclibs  //c语言库文件
|   |
|   \_____一堆c语言库文件
|
\___kernel   //内核源代码
|   |
|   \_____boot.s    //与启动相关的源代码
|   |
|   \_____device  //与设备和硬件相关源代码
|   |
|   \_____init    //初始化代码,包括GDT与IDT等
|   |
|   \_____include //头文件
|   |
|   \_____entry.c //内核程序主函数
|
\___rom      //软盘目录
|   |
|   \_____编译完成的系统文件及其它文件
|
\___scripts  //各种脚本
|   |
|   \_____各种脚本文件,如链接文件,不重要
|
\___floppy.img //软盘映像
|
\___Makefile //不解释
|
\___README.md //不解释
|
\___LICENSE   //不解释

```
