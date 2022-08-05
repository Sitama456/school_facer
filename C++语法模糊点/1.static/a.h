#ifndef a_H
#define a_H
#include <stdio.h>

static int a = 3; // 这句就不会。

//int b = 5; // 这句代码编译时会出错。因为重复定义(被多个cpp文件包含 重复定义了全局变量)
#endif