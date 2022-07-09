/**
 * @file 57.和为s的两个数字.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 
 * 输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。如果有多对数字的和等于s，则输出任意一对即可。
 */
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        set<int> s(nums.begin(), nums.end());
        for (int num : nums) {
            if (s.find(target - num) != s.end()) {
                return { num, target - num };
            }
        }
        return {};
    }
};