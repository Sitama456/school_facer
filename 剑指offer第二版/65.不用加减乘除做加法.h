/**
 * @file 65.不用加减乘除做加法.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 
 * 写一个函数，求两个整数之和，要求在函数体内不得使用 “+”、“-”、“*”、“/” 四则运算符号。
 * 
 */

class Solution {
public:
    int add(int a, int b) {
        while (b) {
            int carry = a & b; // 进位 即两个1就会产生一个进位
            a = a ^ b; // 本位 无进位相加
            // 后续的进位要当成数与 a 相加
            b = (unsigned)carry << 1; // 进位向前进一位
        }
        return a;
    }
};