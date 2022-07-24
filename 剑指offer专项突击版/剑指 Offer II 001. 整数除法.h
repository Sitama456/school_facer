/**
 * @file 剑指 Offer II 001. 整数除法.h
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
 * 给定两个整数 a 和 b ，求它们的除法的商 a/b ，要求不得使用乘号 '*'、除号 '/' 以及求余符号 '%' 。
 */
#include <inttypes.h>
class Solution {
public:
    int divide(int a, int b) {
        // 判断边界
        if (a == INT32_MIN && b == -1) {
            return INT32_MAX;
        }

        if (a == INT32_MIN && b == 1) {
            return INT32_MIN;
        }

        // 判断符号正负
        bool neg = (a > 0) ^ (b > 0);

        // 将值转为负数 
        a = a > 0 ? -a : a;
        b = b > 0 ? -b : b;
        int res = 0;
        int base = 0;
        int value = 0;
        while (a <= b) {
            base = 1;
            value = b;
            // 看a最大能够减b的多少倍 2 4 8 ... 
            while (a - value < value) {
                value *= 2;
                base <<= 1;
            }
            a -= value;
            res += base;
        }
        return neg ? -res : res;
    }
};