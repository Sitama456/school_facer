/**
 * @file 63.股票的最大利润.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖该股票一次可能获得的最大利润是多少？
 * 
 */
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        // vector<int> profit = process(prices, prices.size() - 1);
        // return max(profit[0], profit[1]);
        vector<vector<int>> dp(prices.size(), vector<int>(2));
        dp[0][0] = -prices[0];
        for(int i = 1; i < prices.size(); ++i) {
            dp[i][0] = max(dp[i - 1][0], -prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        }
        return max(dp[prices.size() - 1][0], dp[prices.size() - 1][1]);
    }

    // 贪心 取左最小值 右最大值
    int maxProfit1(vector<int>& prices) {
        int low = 1000000000000;
        int res = 0;
        for (int i = 0; i < prices.size(); ++i) {
            low = min(low, prices[i]);
            res = max(res, prices[i] - low);
        }
        return res;
    }
    // 动态规划
    // 第 n 天持有 0 和不持有 1    股票的最大利润
    vector<int> process(vector<int>& prices, int n) {
        if (n == 0) {
            return {-prices[0], 0};
        }
        // 前一天的利润
        vector<int> profit = process(prices, n - 1);
        vector<int> res(2);
        // 持有股票的利润 前一天持有 但不卖； 前一天没有 今天买
        // 注意 由于只能买卖一次，所以平时的资金是0，而不是profit[1]
        // 因为昨天不持有股票只能是: 要么没有交易，要么已经买卖了一次了 所以资金都是0
        res[0] = max(profit[0], -prices[n]);
        // 不持有股票的利润 前一天不持有，也不买； 前一天持有， 今天卖
        res[1] = max(profit[1], profit[0] + prices[n]);
        return res;
    }
};

// todo  其他股票问题