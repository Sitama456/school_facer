/**
 * @file 05.替换空格.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 
 * 请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
 */
#include <string>
using namespace std;
class Solution {
public:
    string replaceSpace(string s) {
        // 统计有多少个控股
        int oldLen = s.size();
        int spaceCount = 0;
        for (auto c : s) {
            if (c == ' ') {
                spaceCount++;
            }
        }
        int newLen = oldLen + spaceCount * 2;
        int oldIndex = oldLen - 1;
        int newIndex = newLen - 1;
        s.resize(newLen);
        for (; oldIndex >= 0; --oldIndex) {
            if (s[oldIndex] != ' ') {
                s[newIndex--] = s[oldIndex];
            } else {
                s[newIndex--] = '0';
                s[newIndex--] = '2';
                s[newIndex--] = '%';
            }
        }
        return s;
    }
};