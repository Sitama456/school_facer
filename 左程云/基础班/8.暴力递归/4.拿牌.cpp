/**
 * @file 4.拿牌.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 给定一个整数数组arr，代表数值不同的纸牌排成一条线。玩家A和玩家B依次拿走每张
 * 纸牌，规定A先拿，B后拿。每个玩家每次只能拿走最左或者最右的值，玩家A和玩家B都绝顶聪明。
 * 请返回最后获胜者的分数。
 * 
 */

#include <vector>
using namespace std;


int preHand(vector<int>& nums, int L, int R);

int postHand(vector<int>& nums, int L, int R);
/**
 * @brief 先手函数
 * 
 * @param nums 
 * @return int 
 */
int preHand(vector<int>& nums, int L, int R) {
    if (L == R) {
        return nums[L];
    }
    // 拿 L 
    int resL = nums[L] + postHand(nums, L + 1, R);
    int resR = nums[R] + postHand(nums, L, R - 1);
    return max(resL, resR);

}

/**
 * @brief 后手函数
 * 
 * @param nums 
 * @param L 
 * @param R 
 * @return int 
 */
int postHand(vector<int>& nums, int L, int R) {
    if (L == R) {
        return 0;
    }
    // 别人拿的先手
    int resL = preHand(nums, L + 1, R);
    int resR = preHand(nums, L, R - 1);
    return min(resL, resR);
}

int win1(vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }
    return max(preHand(nums, 0, nums.size() - 1), postHand(nums, 0, nums.size() - 1));
}