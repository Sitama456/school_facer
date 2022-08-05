/**
 * @file 032. 最大花费金额[100 分].cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief https://blog.csdn.net/weixin_37580235/article/details/125174868
 * 
 */

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <string.h>
using namespace std;

/**
 * @brief 0 ~ i 范围内自由选择
 * 
 * @param prices 
 * @param i 
 * @param rest 还需要买多少商品
 * @param money 剩余多少钱
 * @return int 
 */
int maxCostMoney(vector<int>& prices, int i, int rest, int money) {
    // 没有东西可买
    if (i == -1) {
        return 0;
    }
    // 买够了
    if (rest == 0) {
        return 0;
    }
    // 买当前物品
    int maxValue = 0;
    if (money >= prices[i]) {
        maxValue = prices[i] + maxCostMoney(prices, i - 1, rest - 1, money - prices[i]);
    }
    // 不买当前物品
    maxValue = max(maxValue, maxCostMoney(prices, i - 1, rest, money));
    return maxValue;
}

int main() {
    string inputStr;
    int money = 0;
    while (1) {
        cin >> inputStr;
        char* tmp = strtok((char *)(inputStr.data()), ",");
        vector<int> prices;
        while (tmp != NULL) {
            prices.push_back(atoi(tmp));
            tmp = strtok(NULL, ",");
        }
        cin >> money;
        cout << maxCostMoney(prices, prices.size(), 3, money);
    }
    return 0;
}