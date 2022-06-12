/**
 * @file 6.字母转换.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 规定 1 和 A 对应，2 和 B对应， 3 和 C 对应...
 * 那么一个数组有多少种对应方式
 * 
 */

#include <vector>
using namespace std;

/**
 * @brief i 之后的转换后多少种方法
 * 
 * @param nums 
 * @param i 
 * @return int 
 */
int transMethods(vector<int>& nums, int i) {
    if (i == nums.size()) {
        return 1;
    }
    if (nums[i] == 0) {
        return 0;
    }

    if (nums[i] == 1) {
        int res = transMethods(nums, i + 1);
        if (i + 1 < nums.size()) {
            res += transMethods(nums, i + 2);
        }
        return res;
    }
    if (nums[i] == 2) {
        int res = transMethods(nums, i + 1);
        if (i + 1 < nums.size() && nums[i + 1] >= 1 && nums[i + 1] <= 6) {
            res += transMethods(nums, i + 2);
        }
        return res;
    }
    return transMethods(nums, i + 1);

}

int AllMethods(vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }

    return transMethods(nums, 0);
}