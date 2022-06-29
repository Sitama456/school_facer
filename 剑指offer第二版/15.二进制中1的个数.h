/**
 * @file 15.二进制中1的个数.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 编写一个函数，输入是一个无符号整数（以二进制串的形式），返回其二进制表达式中数字位数为 '1' 的个数（也被称为 汉明重量).）
 * 
 */
#include <stdint.h>
class Solution {
public:
    int hammingWeight(uint32_t n) {
        // n - 1 让 n 最后一个1变成0 而此1右边0全变为1
        // n & (n - 1) 则让最后一个1变为0.其他位置不变
        int res = 0;
        while (n) {
            res++;
            n = n & (n - 1);
        }
        return res;
    }
};