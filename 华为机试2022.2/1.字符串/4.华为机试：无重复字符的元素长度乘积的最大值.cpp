/**
 * @file 4.华为机试：无重复字符的元素长度乘积的最大值.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 
 * 无重复字符的元素长度乘积的最大值

题目描述：
给定一个元素类型为小写字符串的数组，请计算两个没有相同字符的元素长度乘积的最大值。
如果没有符合条件的两个元素返回0。
输入描述：
输入为一个半角逗号分割的小写字符串数组
2<= 数组长度 <=100
0< 字符串长度 <=50
输出描述
两个没有相同字符的元素长度乘积的最大值

示例 1：

输入
iwdvpbn,hk,iuop,iikd,kadgpf
1
输出
14
1
说明：
数组中有5个元素。
iwdvpbn与hk无相同的字符，满足条件，iwdvpbn的长度为7，hk的长度为2，乘积为14（7*2）。
iwdvpbn与iuop、iikd、kadgpf均有相同的字符，不满足条件。
iuop与iikd、kadgpf均有相同的字符，不满足条件。
————————————————
版权声明：本文为CSDN博主「小朱小朱绝不服输」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/weixin_44052055/article/details/123928875
 */

#include <vector>
#include <string>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;


/**
 * @brief 获取string的int 型id
 * 
 * @param str 
 * @return int 
 */
int getStrId(string str) {
    int num = 0;
    for (char c : str) {
        num |= (1 << (c - 'a'));
    }
    return num;
}

int maxMultStr(vector<string>& strs) {
    int size = strs.size();
    int res = 0;
    for (int i = 0; i < size - 1; ++i) {
        int idi = getStrId(strs[i]);
        for (int j = i + 1; j < size - 1; ++j) {
            int idj = getStrId(strs[j]);
            if (!(idi & idj)) {
                res = max(res, (int)(strs[i].size() * strs[j].size()));
            }
        }
    }
    return res;
}

int main(int argc, char* argv[]) {
    string inputStr;
    while (1) {
        cin >> inputStr;
        vector<string> strs;
        char* tmp = strtok((char *)(inputStr.data()), ",");
        while (tmp != NULL) {
            strs.push_back(tmp);
            tmp = strtok(NULL, ",");
        }
        cout << maxMultStr(strs) << endl;
    }
    return 0;
}