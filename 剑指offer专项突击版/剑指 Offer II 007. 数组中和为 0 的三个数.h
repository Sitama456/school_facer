/**
 * @file 剑指 Offer II 007. 数组中和为 0 的三个数.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 
 * 给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a ，b ，c ，使得 a + b + c = 0 ？请找出所有和为 0 且 不重复 的三元组。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/1fGaJU
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // 从左向右找
        int size = nums.size();
        vector<vector<int>> res;
        for (int i = 0; i < size - 2; i++) {
            // 第一层去重
            // 在这一层中，前面一个数肯定用过了
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int k = size - 1;
            for (int j = i + 1; j < size; ++j) {
                // 第二层去重
                // 在这一层中，前面一个数肯定用过了
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                // 看当前j能让k向左走多远
                while (j < k && nums[i] + nums[j] + nums[k] > 0) {
                    k--;
                }
                // 没有找到一组数
                if (j >= k) {
                    break;
                }
                if (nums[i] + nums[j] + nums[k] == 0) {
                    res.push_back({nums[i], nums[j], nums[k]});
                }
            }
              
        }
        return res;
        
    }
};