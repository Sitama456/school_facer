/**
 * @file 剑指 Offer II 002. 二进制加法.h
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
 * 给定两个 01 字符串 a 和 b ，请计算它们的和，并以二进制字符串的形式输出。

输入为 非空 字符串且只包含数字 1 和 0。 
 */
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int carry = 0; // 进位
        int size1 = a.size();
        int size2 = b.size();
        int i = 0;
        int total = 0;
        string res;
        while (i < size1 && i < size2) {
            total = carry; // 进位
            char c1 = a[i];
            char c2 = b[i];
            total += c1 - '0';
            total += c2 - '0';
            carry = total >= 2 ? 1 : 0;
            total -= carry * 2;
            res.push_back('0' + total);
            i++;
        }
        while (i < size1) {
            total = carry;
            total += a[i] - '0';
            carry = total >= 2 ? 1 : 0;
            total -= carry * 2;
            res.push_back('0' + total);
            i++;
        }

        while (i < size2) {
            total = carry;
            total += b[i] - '0';
            carry = total >= 2 ? 1 : 0;
            total -= carry * 2;
            res.push_back('0' + total);
            i++;
        }

        if (carry != 0) res.push_back('0' + carry);

        reverse(res.begin(), res.end());
        return res;
    }
};