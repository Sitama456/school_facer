/**
 * @file 16.数值的整数次方.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 实现 pow(x, n) ，即计算 x 的 n 次幂函数（即，xn）。不得使用库函数，同时不需要考虑大数问题。
 * 
 */

class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0) {
            return 0;
        }

        long b = n; // 防止溢出
        // 二分 x^1 x^2 x^4 ...
        double res = 1;

        if (b < 0) { // 将其转化为 n >= 0 的范围来
            b = -b;
            x = 1 / x;
        }
        while (b) {
            if (b & 1) { // 如果 n 是奇数 则要多乘一个x
                res *= x;
            }
            x *= x;      // x ^ 2
            b >>= 1;    // n /= 2;
        }
        return res;
    }
};