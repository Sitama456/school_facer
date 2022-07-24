/**
 * @file  67.把字符串转换成整数.h
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
 * 写一个函数 StrToInt，实现把字符串转换成整数这个功能。不能使用 atoi 或者其他类似的库函数。

 

首先，该函数会根据需要丢弃无用的开头空格字符，直到寻找到第一个非空格的字符为止。

当我们寻找到的第一个非空字符为正或者负号时，则将该符号与之后面尽可能多的连续数字组合起来，作为该整数的正负号；假如第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成整数。

该字符串除了有效的整数部分之后也可能会存在多余的字符，这些字符可以被忽略，它们对于函数不应该造成影响。

注意：假如该字符串中的第一个非空格字符不是一个有效整数字符、字符串为空或字符串仅包含空白字符时，则你的函数不需要进行转换。

在任何情况下，若函数不能进行有效的转换时，请返回 0。

说明：

假设我们的环境只能存储 32 位大小的有符号整数，那么其数值范围为 [−231,  231 − 1]。如果数值超过这个范围，请返回  INT_MAX (231 − 1) 或 INT_MIN (−231) 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/ba-zi-fu-chuan-zhuan-huan-cheng-zheng-shu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include <string>
#include <inttypes.h>
using namespace std;
class Solution {
public:
    int strToInt(string str) {
        int size = str.size();
        if (str.empty()) return 0;
        // 1. 去掉开头的空格
        int i = 0;
        int j = size - 1;
        while (i < size && str[i] == ' ') {
            i++;
        }
        
        if (i == size) return 0;
        // 2. 如果不是字符
        if ((str[i] > '9' || str[i] < '0') && (str[i] != '+' && str[i] != '-')) {
            return 0;
        }

        bool neg = str[i] == '-';
        
        int minq = INT32_MIN / 10;
        int minr = INT32_MAX % 10;
        int res = 0;
        int cur = 0;
        // 跳过开头的符号
        if (str[i] == '+' || str[i] == '-') i++;
        for (; i < size; ++i) {
            if (str[i] > '9' || str[i] < '0') break;
            // 以负数的形式接住这个数字
            cur = '0' - str[i];
            // 转换过程中的溢出 注意这里是负数的比较 值越小则数字越大
            if (res < minq || (res == minq && cur < minr)) {
                return neg ? INT32_MIN : INT32_MAX;
            }
            res = res * 10 + cur;
        }
        // 如果不是负数
        if (res == INT32_MIN && !neg) {
            return INT32_MAX;
        }
        return neg ? res : -res;

    }
};