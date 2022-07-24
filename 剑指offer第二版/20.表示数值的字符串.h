/**
 * @file 20.表示数值的字符串.h
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
 * 请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。

数值（按顺序）可以分成以下几个部分：

若干空格
一个 小数 或者 整数
（可选）一个 'e' 或 'E' ，后面跟着一个 整数
若干空格
小数（按顺序）可以分成以下几个部分：

（可选）一个符号字符（'+' 或 '-'）
下述格式之一：
至少一位数字，后面跟着一个点 '.'
至少一位数字，后面跟着一个点 '.' ，后面再跟着至少一位数字
一个点 '.' ，后面跟着至少一位数字
整数（按顺序）可以分成以下几个部分：

（可选）一个符号字符（'+' 或 '-'）
至少一位数字
部分数值列举如下：

["+100", "5e2", "-123", "3.1416", "-1E-16", "0123"]
部分非数值列举如下：

["12e", "1a3.14", "1.2.3", "+-5", "12e+5.4"]

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/biao-shi-shu-zhi-de-zi-fu-chuan-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    // 有限状态机
    // 0 : 起始的blank
    // 1 : e之前的正负号
    // 2 : 小数点之前的数字
    // 3 : 小数点之后的数字
    // 4 : 小数点前为空格时，小数点之后的数字
    // 5 : 科学计数符号 e
    // 6 : e之后的符号
    // 7 : e 之后的数字
    // 8 : 尾部的空格
    // s中每个字符只有一种状态，根据其后面的字符跳转至相应的状态
    bool isNumber(string s) {
        vector<map<char, int>> maps(9);
        // 每个状态只看之后能填什么字符即可 之前的不用管
        // 第一种状态 起始的blank
        maps[0].insert({' ', 0}); // 开头的空格
        maps[0].insert({'s', 1}); // e 之前的符号
        maps[0].insert({'d', 2}); // dot之前的数字
        maps[0].insert({'.', 4}); // dot前为空格时，dot之后的数字;

        // e之前的正负号
        maps[1].insert({'d', 2}); // 小数点前的数字
        maps[1].insert({'.', 4}); // dot为前为空时, dot 后的数字

        // 小数点前的数字
        maps[2].insert({'d', 2}); // 小数点前的数字
        maps[2].insert({'.', 3}); // 小数点后的数字
        maps[2].insert({'e', 5}); // 科学计数法符号e
        maps[2].insert({' ', 8}); // 尾部空格

        // 小数点之后的数字
        maps[3].insert({'d', 3}); // 小数点后的数字
        maps[3].insert({'e', 5}); // e
        maps[3].insert({' ', 8}); // 尾部空格

        // 小数点前为空格时，小数点之后的数字
        maps[4].insert({'d', 3}); // 小数点之后的数字

        // e
        maps[5].insert({'s', 6}); // e之后的符号
        maps[5].insert({'d', 7}); // e之后的数字

        // e之后的符号
        maps[6].insert({'d', 7}); // e 之后的数字

        // e 之后的数字
        maps[7].insert({' ', 8}); // 尾部空格
        maps[7].insert({'d', 7}); // e 之后的数字

        maps[8].insert({' ', 8});
        int p = 0; // 初始状态为空格 空格后面可以填什么字符?
        char c;
        char t = '?';
        for (int i = 0; i < s.size(); ++i) {
            c = s[i];
            if (c >= '0' && c <= '9') t = 'd';
            else if (c == ' ') t = ' ';
            else if (c == '.') t = c;
            else if (c == 'E' || c == 'e') t = 'e';
            else if (c == '+' || c == '-') t = 's';
            else t = '?';
            // 当前状态下，没有可跳转的状态 返回false
            if (maps[p].find(t) == maps[p].end()) {
                return false;
            }
            // 状态转移
            p = maps[p][t];

        }

        // 结尾的状态只能是
        return p == 2 || p == 3 || p == 7 || p == 8;


    }
};