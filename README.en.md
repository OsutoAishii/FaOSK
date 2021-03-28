## FaOSK Operating system kernel
The FaOSK operating system kernel is a system kernel running on the 32-bit processor of the Intel x86 platform, which can run in virtual machines such as qemu, bochs, virtualbox, vmware, or on a physical machine.

### System function list
The current FaOSK kernel is still under development and has very few functions. It has only been interrupted at present, but this kernel will continue to be updated.
This kernel is very suitable for people who are new to operating systems for learning purposes. It has a lot of code comments. As long as there is an operating system book next to it, there is basically no problem in understanding its source code.

### Development environment setup

##### 1. Clone the source code:

Use gitee source:

```
git clone https://gitee.com/FirstArchve/FaOSK.git
```
Use github source:

```
git clone https://github.com/FirstArchve/FaOSK.git
```
##### 2. Install Toolkit

Debian/ubuntu/kill:

```
sudo apt-get install gcc nasm qemu qemu-system-x86
```
Red hat/Fedora/CentOS:

```
sudo yum install gcc nasm qemu qemu-system-x86
```
##### 3. Other compilation environment preparation

Create a folder in to mount the floppy disk image and write system files (see Makefile for details).

```
sudo mkdir mnt
```
### Commands used during development

Compile all source code:

```
make
```
Run in qemu (need to compile and write the new system file into the floppy disk image):

```
make run
```
Run in bochs (need to installed bochs and compile and write the new system file into the floppy disk image):

```
make bochs
```
Clean up useless process files:

```
make clean
```
The above are commonly used commands in development, please refer to Makefile for other commands.

### Project structure

```
FaOSK
|
\___faclibs  //c language library file
|   |
|   \_____A bunch of C language library files
|
\___kernel   //Kernel source code
|   |
|   \_____boot    //Source code related to startup
|   |
|   \_____device  //Source code related to equipment and hardware
|   |
|   \_____init    //Initialization code, including GDT and IDT, etc.
|   |
|   \_____include //Headfile
|   |
|   \_____entry.c //Kernel main function
|
\___rom      //Floppy Disk Directory
|   |
|   \_____Compiled system files and other files
|
\___scripts  //Various scripts
|   |
|   \_____Various script files, such as link files, are not important
|
\___floppy.img //Floppy image
|
\___Makefile //No explanation
|
\___README.md //No explanation
|
\___LICENSE   //No explanation

```
