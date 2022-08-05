/**
 * @file 040. VLAN 资源池[100 分].cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief https://blog.csdn.net/weixin_37580235/article/details/125194305
 * map.lower_bound(key) : 返回第一个键值 >= key 的迭代器
 * map.upper_bound(key) : 返回第一个键值 > key 的迭代器
 * 但这道题用不上
 * 
 */

#include <vector>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;

struct range {
    int start = 0;
    int end = 0;
    range(int start, int end) : start(start), end(end) {}
    range(string str) {
        int pos = str.find('-');
        if (pos != -1) {
            start = atoi(str.substr(0, pos).c_str());
            end = atoi(str.substr(pos + 1).c_str());
        } else {
            start = end = atoi(str.c_str());
        }
    }
};

vector<range> getVlanPool(vector<string>& str, int requestNum) {
    int size = str.size();
    vector<range> res;
    int rangeStart = 0;
    int rangeEnd = 0;
    int pos = -1;
    for (int i = 0; i< size; ++i) {
        string rangeStr = str[i];
        pos = rangeStr.find('-');
        if (pos != -1) {
            rangeStart = atoi(rangeStr.substr(0, pos).c_str());
            rangeEnd = atoi(rangeStr.substr(pos + 1).c_str());
        } else {
            rangeStart = rangeEnd = atoi(rangeStr.c_str());
        }
        if (requestNum >= rangeStart && requestNum <= rangeEnd) {
            // 分裂
            int newStart1 = rangeStart;
            int newEnd1 = requestNum - 1;
            int newStart2 = requestNum + 1;
            int newEnd2 = rangeEnd;
            if (newStart1 <= newEnd1) {
                res.push_back({newStart1, newEnd1});
            }
            if (newStart2 <= newEnd2) {
                res.push_back({newStart2, newEnd2});
            }
        } else {
            res.push_back({rangeStart, rangeEnd});
        }
    }
    // 
    return res;
}