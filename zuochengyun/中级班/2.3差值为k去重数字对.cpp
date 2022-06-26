/**
 * @file 2.3差值为k去重数字对.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 给定一个数字 找到差值为k的去重数字对
 * 
 */
#include <vector>
#include <set>
using namespace std;

vector<vector<int>> kpair(vector<int>& nums, int k) {
    set<int> s(nums.begin(), nums.end());
    vector<vector<int>> res;
    for (auto num : nums) {
        // 升序地记录所有数字对
        if (s.find(num + k) != s.end()) {
            res.push_back({num, num + k});
        }
    }
    return res;
}