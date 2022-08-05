/**
 * @file 16.华为机试：区间交集.cpp
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
 * 【编程题目 |200分】区间交集 【2021 H2,2022 Q1,Q2 考试题】

题目描述
【区间交集】

给定一组闭区间，其中部分区间存在交集。

任意两个给定区间的交集，称为公共区间(如:[1,2],[2,3]的公共区间为[2,2]，[3,5],[3,6]的公共区间为[3,5])。

公共区间之间若存在交集，则需要合并(如:[1,3],[3,5]区间存在交集[3,3]，需合并为[1,5])。

按升序排列输出合并后的区间列表。

输入描述
一组区间列表，区间数为 N: 0<=N<=1000;区间元素为 X: -10000<=X<=10000。

输出描述
升序排列的合并区间列表

备注
1、区间元素均为数字，不考虑字母、符号等异常输入。

2、单个区间认定为无公共区间。

示例：
输入
1 3 2 4 4 8 5 9
1
输出
2 3 4 4 5 8
1
说明
[1,3]、[2,4]、[4,8]、[5,9] 四个区间
[1,3]与[2,4]交集为[2,3]，[1,3]与[4,8]、[5,9]没有交集
[2,4]与[4,8]]交集为[4,4]。[2,4]与[5,9]没有交集
[4,8]与[5,9]的交集为[5,8]
所以最终的输出为[2,3]、[4,4]、[5,8]
1
2
3
4
5
输入
1 6 2 5 5 7
1
输出
2 6
1
说明
[1,6]、[2,5]的交集为[2,5]，[1,6]、[5,7]的交集为[5,6]
[2,5]、[5,7]的交集为[5,5]
最后的输出为：2 6
1
2
3
输入
1 2 3 4
1
输出
None  (这里没看到题目上具体要求输出什么，根据题目情况临场发挥即可)
1
注：这道题目的输入输出有多个版本，有一行的，有分行的，有带中括号列表的，我是按一行读取，只是输入输出的不同而已，题目解法是一样的。
————————————————
版权声明：本文为CSDN博主「小朱小朱绝不服输」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/weixin_44052055/article/details/125833252
 */

#include <string>
#include <vector>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

struct range {
    int left = 0;
    int right = 0;
    range() {}
    range(int l, int r) : left(l), right(r) {}
};

bool cmp(range a, range b) {
    return a.left < b.left;
}

vector<range> interSection(vector<range>& ranges) {
    int size = ranges.size();
    // 求交集
    vector<range> interSec;
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            int left = max(ranges[i].left, ranges[j].left);
            int right = min(ranges[i].right, ranges[j].right);
            if (left <= right) {
                range x(left, right);
                interSec.push_back(x);
            }
        }
    }
    // 交集按起始点排序
    sort(interSec.begin(), interSec.end(), cmp);
    // 合并交集区间
    vector<range> mergeSec;
    for (int i = 0; i < interSec.size(); ++i) {
        // 如果merge中还没有区间
        // 或者要加入的区间的起点大于merge中最后一个的中点 证明没有重合
        if (mergeSec.empty() || interSec[i].left > mergeSec.back().right) {
            mergeSec.push_back(interSec[i]);
        } else {
            // 有重合 让当前最后一个的右区间取两者最大值
            mergeSec.back().right = max(mergeSec.back().right, interSec[i].right);
        }
    }
    return mergeSec;
    
}

int main(int argc, char* argv[]) {
    string inputStr;
    while (1) {
        getline(cin, inputStr);
        vector<int> nums;
        vector<range> ranges;
        char* tmp = strtok((char*)(inputStr.data()), " ");
        while (tmp != NULL) {
            nums.push_back(atoi(tmp));
            tmp = strtok(NULL, " ");
        }
        for (int i = 0; i < nums.size(); i += 2) {
            range x(nums[i], nums[i + 1]);
            ranges.push_back(x);
        }
        vector<range> res = interSection(ranges);
        for (range x : res) {
            cout << x.left << " " << x.right << " ";
        }
        cout << endl;
    }
    return 0;
}