/**
 * @file 58.1. 翻转单词顺序.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。为简单起见，标点符号和普通字母一样处理。例如输入字符串"I am a student. "，则输出"student. a am I"。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/fan-zhuan-dan-ci-shun-xu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include <string>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        if (s.empty()) return "";
        int start = 0;
        int end = s.size() - 1;
        while (start < s.size() && s[start] == ' ') {
            start++;
        }
        while(end >= 0 && s[end] == ' ') {
            end--;
        }
        int i = end;
        int j = end;
        string res;
        while(i >= start) {
            while (i >= start && s[i] != ' ') {
                i--;
            }
            // 添加字符串
            res += s.substr(i + 1, j - i);
            res += " ";
            while (i >= start && s[i] == ' ') i--;
            j = i;
        }
        int size = res.size();
        for (int k = size - 1; k >= 0; k--) {
            if (res[k] != ' ') {
                break;
            }
            res.pop_back();
        }
        return res;

    }
};