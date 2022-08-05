/**
 * @file 035. 玩牌高手[100 分].cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief https://blog.csdn.net/weixin_37580235/article/details/125193864
 * 
 */
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
// 表示第i轮的分数
int maxPoints(vector<int>& nums, int i) {
    if (i < 0) {
        return 0;
    }
    // 选择牌数
    int num1 = nums[i] + maxPoints(nums, i - 1);
    // 不选择
    int num2 = maxPoints(nums, i - 3);
    return max(num1, num2);
}

int main() {
    string inputStr;
    while (1) {
        cin >> inputStr;
        char* tmp = strtok((char*)(inputStr.data()), ",");
        vector<int> nums;
        while (tmp != NULL) {
            nums.push_back(atoi(tmp));
            tmp = strtok(NULL, ",");
        }
        cout << maxPoints(nums, nums.size() - 1) << endl;
    }
    return 0;
}