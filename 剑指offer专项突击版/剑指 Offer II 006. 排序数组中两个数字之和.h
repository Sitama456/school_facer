/**
 * @file 剑指 Offer II 006. 排序数组中两个数字之和.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */
 
 /**
  * @brief 
  * 给定一个已按照 升序排列  的整数数组 numbers ，请你从数组中找出两个数满足相加之和等于目标数 target 。

函数应该以长度为 2 的整数数组的形式返回这两个数的下标值。numbers 的下标 从 0 开始计数 ，所以答案数组应当满足 0 <= answer[0] < answer[1] < numbers.length 。

假设数组中存在且只存在一对符合条件的数字，同时一个数字不能使用两次。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/kLl5u1
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
  * 
  */
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        map<int, int> s;
        vector<int> res;
        for (int i = 0; i < numbers.size(); ++i) {
            if (s.find(target - numbers[i]) != s.end()) {
                return {s[target - numbers[i]], i};
            }
            s[numbers[i]] = i;
        }
        return res;
    }
};