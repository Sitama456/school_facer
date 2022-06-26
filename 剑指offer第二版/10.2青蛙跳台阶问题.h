/**
 * @file 10.2青蛙跳台阶问题.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 
 * 一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/qing-wa-tiao-tai-jie-wen-ti-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include <vector>
#include <math.h>
using namespace std;
class Solution {
public:
    int numWays(int n) {
        return numWays1(n);
    }

    int numWays1(int n) {
        if (n == 1 || n == 0) return 1;
        if (n == 2) return 2;
        vector<int> dp(n + 1);
        int mod = pow(10, 9) + 7;
        dp[0] = dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
            dp[i] = dp[i] % mod;
        }
        return dp[n];
    }
};