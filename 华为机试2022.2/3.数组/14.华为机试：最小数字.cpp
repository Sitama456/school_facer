/**
 * @file 14.华为机试：最小数字.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 
 * 【编程题目 | 100分】最小数字 [ 100 / 中等 ]

最小数字
题目描述：
给定一个整型数组，请从该数组中选择3个元素组成最小数字并输出（如果数组长度小于3，则选择数组中所有元素来组成最小数字）。

输入描述：
一行用半角逗号分割的字符串记录的整型数组，0 < 数组长度 <= 100，0 < 整数的取值范围 <= 10000。

输出描述：
由3个元素组成的最小数字，如果数组长度小于3，则选择数组中所有元素来组成最小数字。

示例 1：
输入
21,30,62,5,31
1
输出
21305
1
说明
数组长度超过3，需要选3个元素组成最小数字，21305由21,30,5三个元素组成的数字，为所有组合中最小的数字

示例 2：
输入
5,21
1
输出
215
1
说明
数组长度小于3，选择所有元素组成最小值，215为最小值
————————————————
版权声明：本文为CSDN博主「小朱小朱绝不服输」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/weixin_44052055/article/details/124060273
 */

#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;



bool cmp(int x, int y) {
    string xstr = to_string(x);
    string ystr = to_string(y);
    return atoi((xstr + ystr).c_str()) < atoi((ystr + xstr).c_str());
}

int getMinNum(vector<int>& nums) {
    // 排序 取最小的3个数字
    sort(nums.begin(), nums.end());
    int k = 3;
    int len = nums.size();
    vector<int> tmp;
    for (int i = 0; i < min(len, k); ++i) {
        tmp.push_back(nums[i]);
    }
    // 排序
    sort(tmp.begin(), tmp.end(), cmp);
    string tmpStr;
    for (int i = 0; i < tmp.size(); ++i) {
        tmpStr += to_string(tmp[i]);
    }
    return atoi(tmpStr.c_str());
}

int main(int argc, char* argv[]) {
    string inputStr;
    while (1) {
        cin >> inputStr;
        vector<int> nums;
        char* tmp = strtok((char *)(inputStr.data()), ",");
        while (tmp != NULL) {
            nums.push_back(atoi(tmp));
            tmp = strtok(NULL, ",");
        }
        cout << getMinNum(nums) << endl;
    }
    return 0;
}