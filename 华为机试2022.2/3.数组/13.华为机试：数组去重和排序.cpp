/**
 * @file 13.华为机试：数组去重和排序.cpp
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
 * 编程题目 | 100分】数组去重和排序 [ 100 / 中等 ]

数组去重和排序
题目描述：
给定一个乱序的数组，删除所有的重复元素，使得每个元素只出现一次，并且按照出现的次数从高到低进行排序，相同出现次数按照第一次出现顺序进行先后排序。

输入描述：
一个数组

输出描述：
去重排序后的数组

示例 1：
输入
1,3,3,3,2,4,4,4,5
1
输出
3,4,1,2,5
1
备注
数组大小不超过100 数组元素值大小不超过100

思路分析
————————————————
版权声明：本文为CSDN博主「小朱小朱绝不服输」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/weixin_44052055/article/details/124053155
 */

#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}

vector<pair<int, int>> sort(vector<int>& nums) {
    map<int, int> count;
    for (int num : nums) {
        count[num]++;
    }
    vector<pair<int, int>> res;
    for (auto& entry : count) {
        res.push_back(entry);
    }
    sort(res.begin(), res.end(), cmp);
    return res;
}

int main(int argc, char* argv[]) {
    string inputStr;
    while (1) {
        cin >> inputStr;
        char* tmp = strtok((char *)(inputStr.data()), ",");
        vector<int> nums;
        while (tmp != NULL) {
            nums.push_back(atoi(tmp));
            tmp = strtok(NULL, ",");
        }
        vector<pair<int, int>> res = sort(nums);
        int len = res.size();
        for (int i = 0; i < len - 1; ++i) {
            cout << res[i].first << ",";
        }
        if (len - 1 >= 0) {
            cout << res[len - 1].first << endl;
        }
    }
    return 0;
}