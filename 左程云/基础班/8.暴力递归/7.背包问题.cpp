/**
 * @file 7.背包问题.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 给定两个长度都为N的数组weights和values，weights[i] 和 values[i]分别代表i号
 * 物品的重量和价值。给定一个整数bag,表示一个载重bag的袋子，装的物品不能超过这个重量。
 * 返回能装下最多的价值是多少
 * 
 */
#include <vector>
using namespace std;
/**
 * @brief i 往后的货物自由选择 形成的最大价值
 * 
 * @param weights 
 * @param values 
 * @param i 
 * @param alreadyweight 
 * @param bag 
 * @return int 
 */
int process1(vector<int>& weights, vector<int>& values, int i, int alreadyweight, int bag) {
    if (alreadyweight > bag) {
        return 0;
    }
    if (i == weights.size()) {
        return 0;
    }

    int res1 = 0;
    // 当前物品不超重才选当前物品
    if (alreadyweight + weights[i] <= bag) {
        res1 = values[i] + process1(weights, values, i + 1, alreadyweight + weights[i], bag);
    }
    // 不选当前物品
    int res2 = process1(weights, values, i + 1, alreadyweight, bag);
    return max(res1, res2);
}