/**
 * @file 46.把数字翻译成字符串.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。

 

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include <string>
using namespace std;
class Solution {
public:
    int translateNum(int num) {
        string s = to_string(num);
        return process(s, 0);
    }

    // 0 ~ i - 1 位置不管，i 位置之后的转换的方法数
    int process(string& s, int i) {
        if (i == s.size()) { // 找到一种 前面的转化
            return 1;
        }
        // 当前数字
        int cur = s[i] - '0';
        if (cur == 0 || cur >= 3) {
            // 只有一种转化形式 就是它本身作为一个字符
            return process(s, i + 1);
        }
        if (cur == 1) {
            // 本身作为一个字符转换
            int res = process(s, i + 1);
            if (i + 1 < s.size()) {
                res += process(s, i + 2);
            }
            return res;
        }
        if (cur == 2) {
            int res = process(s, i + 1);
            if (i + 1 < s.size() && ('0' <= s[i + 1] && s[i + 1] <= '5')) {
                res += process(s, i + 2);
            }
            return res;
        }
        return 0;
    }
};