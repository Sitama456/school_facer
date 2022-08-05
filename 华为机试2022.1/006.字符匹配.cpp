/**
 * @file 006.字符匹配.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief https://blog.csdn.net/weixin_37580235/article/details/125114391
 * 
 */
#include <string>
#include <vector>
#include <iostream>
#include <string.h>
using namespace std;
/**
 * @brief str2 能否匹配 str1 i j 表示当前匹配位置
 * 
 * @param str1 
 * @param str2 
 * @param i 
 * @param j 
 * @return true 
 * @return false 
 */
bool isMatched(string& str1, string& str2, int i, int j) {
    // 如果字符串空了 正则串还没有空
    if (i == str1.size()) {
        // str2剩余部分必须全为*
        for (; j < str2.size(); ++i) {
            if (str2[j] != '*') {
                return false;
            }
        }
        return true;
    }
    // 字符串没空 正则串空了
    if (j == str2.size()) return false;

    // 普通位置
    if (str2[j] == '.') {
        return isMatched(str1, str2, i + 1, j + 1);
    } else if (str2[j] == '*') {
        // 可以选择 匹配1个 或者匹配多个
        return isMatched(str1, str2, i + 1, j) || isMatched(str1, str2, i + 1, j + 1);
    } else {
        return str1[i] == str2[j] && isMatched(str1, str2, i + 1, j + 1);
    }

}

int main() {
    string inputStr;
    while (1) {
        getline(cin, inputStr);
        vector<string> strs;
        char* tmp = strtok((char*)inputStr.data(), " ");
        while (tmp != NULL) {
            strs.push_back(tmp);
            tmp = strtok(NULL, " ");
        }
        cin >> inputStr;
        vector<int> res;
        for (int i = 0; i < strs.size(); ++i) {
            if (isMatched(strs[i], inputStr, 0, 0)) {
                res.push_back(i);
            }
        }
        for (int i = 0; i < res.size() - 1; ++i) {
            cout << res[i] << ",";
        }
        if (!res.empty()) {
            cout << res[res.size() - 1];
        }
    }
    return 0;
}