// Filename:  ports.h
// Description:  关于端口读写的定义
// Compiler:  gcc

#ifndef PORTS_H
#define PORTS_H

#include "types.h"

// 端口写一个字节
void outb(uint16 port, uint8 value);

// 端口读一个字节
uint8 inb(uint16 port);

// 端口读一个字
uint16 inw(uint16 port);

#endif
