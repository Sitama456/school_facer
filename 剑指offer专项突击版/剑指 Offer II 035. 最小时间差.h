/**
 * @file 剑指 Offer II 035. 最小时间差.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 
 * 给定一个 24 小时制（小时:分钟 "HH:MM"）的时间列表，找出列表中任意两个时间的最小时间差并以分钟数表示。
 */
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(), timePoints.end());
        int res = INT32_MAX;
        for (int i = 0; i < timePoints.size() - 1; ++i) {
            int time1 = timeToInt(timePoints[i]);
            int time2 = timeToInt(timePoints[i + 1]);
            res = min(res, time2 - time1);
        }
        // 首尾的时间差
        int size = timePoints.size();
        res = min(res, timeToInt(timePoints[0]) + 24 * 60 - timeToInt(timePoints[size - 1]));
        return res;

    }
    // b > a
    int timeToInt(string& s) {
        return ((s[0] - '0') * 10 + s[1] - '0') * 60 + (s[3] - '0') * 10 + s[4] - '0';
    }
};