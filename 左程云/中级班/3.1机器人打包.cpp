/**
 * @file 3.1机器人打包.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 有一排从左到右的打包机器，自动装置会抓取一批物品放到每个机器上。每个机器的物品有多有少，需要工人
 * 移动物品而达到每个机器物品数量相等才能打包。一次只能移动一个物品，并且只在相邻机器上移动。请计算搬动最少
 * 轮数的前提下，使每个机器的物品数量相等。如果做不到，返回-1
 * leetcode 洗衣机问题
 * 
 */

/**
 * @brief 
 * 1) 总衣服 sum % N == 0 
 * 2) 以 i 位置，计算其左侧需要或多出几件衣服 右侧需要或多出几件衣服
 *    A) 如果两侧都是负数， 则 i 位置至少需要两侧绝对值相加的轮数
 *    B) 如果两侧都是正数， 则 i 位置至少需要绝对值大的轮数
 *    C) 左负右正， 则 i 位置至少需要绝对值大的轮数
 *    D) 左正右负，同C)
 * 3) 求出每个位置的瓶颈，最痛的那个瓶颈就是答案
 */
#include <vector>
#include <math.h>
using namespace std;

int MinOps(vector<int> arr) {
    if (arr.empty()) {
        return false;
    }
    int size = arr.size();
    int sum = 0;
    for (auto num : arr) {
        sum += num;
    }
    if (sum % size != 0) {
        return -1;
    }
    int avg = sum / size;
    int ans = 0;
    int leftSum = 0;
    for (int i = 0; i < size; ++i) {
        // 左侧 剩余 正数需要仍 负数需要输入
        int leftRest = leftSum - i * avg;
        int rightRest = (sum - leftSum - arr[i]) - (size - i - 1) * avg;
        if (leftRest < 0 && rightRest < 0) {
            ans = max(ans, abs(leftRest) + abs(rightRest));
        } else {
            ans = max(ans, max(abs(leftRest), abs(leftRest)));
        }
        leftSum += arr[i];
    }
    return ans;
}