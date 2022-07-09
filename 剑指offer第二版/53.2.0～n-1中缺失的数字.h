/**
 * @file 53.2.0～n-1中缺失的数字.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 
 * 一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0～n-1之内。在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/que-shi-de-shu-zi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <vector>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i = 0;
        for (auto num : nums) {
            if (num != i) {
                return i;
            }
            i++;
        }
        return i;
    }
};