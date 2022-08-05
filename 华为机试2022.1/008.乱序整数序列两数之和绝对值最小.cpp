/**
 * @file 008.乱序整数序列两数之和绝对值最小.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief https://blog.csdn.net/weixin_37580235/article/details/125114416
 * 排序之后从0开始往两边尝试
 */

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> getMinSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    // 负数与整数分界处
    int left = -1;
    int len = nums.size();
    while (left < len - 1 && nums[left + 1] < 0) {
        left++;
    }
    // 没有负数
    if (left == -1) {
        return {nums[0], nums[1], nums[0] + nums[1]};
    }
    // 非负数
    int right = left + 1;
    // 全是负数
    if (right == len) {
        return { nums[len - 2], nums[len - 1], -nums[len - 2] - nums[len - 1]};
    }
    int minSum = __INT32_MAX__;
    int sum = 0;
    while (left >= 0 && right < len) {
        sum = abs(nums[left] + nums[right]);
        minSum = min(minSum, sum);
        if (sum == 0) {
            break;
        } else if (sum > 0) {
            --left;
        } else {
            ++right;
        }
    }
    cout << minSum;

}