/**
 * @file HJ20 密码验证合格程序.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 
 * 描述
密码要求:

1.长度超过8位

2.包括大小写字母.数字.其它符号,以上四种至少三种

3.不能有长度大于2的包含公共元素的子串重复 （注：其他符号不含空格或换行）

数据范围：输入的字符串长度满足 1 \le n \le 100 \1≤n≤100 
输入描述：
一组字符串。

输出描述：
如果符合要求输出：OK，否则输出NG
 */

#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
bool validPassword(string& s);
int main()
{
    string inputStr;
    while (cin >> inputStr) {
        if (validPassword(inputStr)) {
            cout << "OK" << endl;
        } else {
            cout << "NG" << endl;
        }
    }
    return 0;
}

bool validPassword(string& s) {
    if (s.size() <= 8) return false;
    bool hasBigChar = false;
    bool hasSmallChar = false;
    bool hasNum = false;
    bool hasSpec = false;
    // 大于2的公共元素字串重复 
    // 只需要判断长度为3的窗口就行了
    int left = 0;
    int right = 0;
    unordered_set<string> st;
    while (right < s.size()) {
        // 右边界进来一个值
        char c = s[right];
        if (c >= '0' && c <= '9') {
            hasNum = true;
        } else if (c >= 'a' && c <= 'z') {
            hasSmallChar = true; 
        } else if (c >= 'A' && c <= 'Z') {
            hasBigChar = true;
        } else {
            hasSpec = true;
        }
        // 左边界要出去一个值
        if (right - 3 + 1 >= 0) {
            // 重复了
            string tmp = s.substr(right - 2, 3);
            if (st.find(tmp) != st.end()) {
                return false;
            } 
            st.insert(tmp);
            
        }
        right++;
    }
    int kind = 0;
    if (hasBigChar) kind++;
    if (hasSmallChar) kind++;
    if (hasNum) kind++;
    if (hasSpec) kind++;
    return kind >= 3;
    
}