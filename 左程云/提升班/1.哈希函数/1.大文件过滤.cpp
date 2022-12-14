/**
 * @file 1.大文件过滤.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 有一个大文件，内容都是无符号整数。0 ~ 42 亿。有40亿个。只给1G的内存,返回出现次数最多
 * 的数是哪个数
 * 
 * 经典解法:用哈希表统计，需要内存 40亿 * 8 = 320亿B = 32G 内存不够
 * 
 * 分治解法:
 * 1) 所有数调用一个hash函数后再模100：f(an) % 100。根据模出来的数发给某个小文件
 * 2) 对每个小文件再用hash表统计词频
 */