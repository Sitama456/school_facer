/**
 * @file 64.求1+2+…+n.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 
 * 求 1+2+...+n ，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
 * 
 */

class Solution {
public:
    int res = 0;
    int sumNums(int n) {
        // base case 短路保护
        bool tmp = n >= 1 && sumNums(n - 1);
        res += n;
        return res;
    }
};