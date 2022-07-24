/**
 * @file  61.扑克牌中的顺子.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 从若干副扑克牌中随机抽 5 张牌，判断是不是一个顺子，即这5张牌是不是连续的。2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为 0 ，可以看成任意数字。A 不能视为 14。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/bu-ke-pai-zhong-de-shun-zi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int oneCount = 0;
        int needOneCout = 0;
        int size = nums.size();
        for (int i = 0; i < size - 1; ++i) {
            if (nums[i] == 0) {
                oneCount++;
            } else {
                if (nums[i] == nums[i + 1]) return false;
                needOneCout += nums[i + 1] - nums[i] - 1;
            }
        }
        return oneCount >= needOneCout;
    }
};