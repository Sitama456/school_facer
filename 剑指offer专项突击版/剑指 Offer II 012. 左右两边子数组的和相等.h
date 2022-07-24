/**
 * @file 剑指 Offer II 012. 左右两边子数组的和相等.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 
 * 给你一个整数数组 nums ，请计算数组的 中心下标 。

数组 中心下标 是数组的一个下标，其左侧所有元素相加的和等于右侧所有元素相加的和。

如果中心下标位于数组最左端，那么左侧数之和视为 0 ，因为在下标的左侧不存在元素。这一点对于中心下标位于数组最右端同样适用。

如果数组有多个中心下标，应该返回 最靠近左边 的那一个。如果数组不存在中心下标，返回 -1 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/tvdfij
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <vector>
using namespace std;
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if (nums.empty()) return -1;
        vector<int> preSums(nums.size());
        preSums[0] = 0;
        int sum = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            preSums[i] = sum;
            sum += nums[i];
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (sum - preSums[i] == preSums[i] + nums[i]) {
                return i;
            }
        }
        return -1;
    }
};