/**
 * @file 剑指 Offer II 003. 前 n 个数字二进制中 1 的个数.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */
 
 /**
  * @brief 
  * 给定一个非负整数 n ，请计算 0 到 n 之间的每个数字的二进制表示中 1 的个数，并输出一个数组。
  */
#include <vector>
using namespace std;
class Solution {
public:
    // 奇数一定比前面的偶数多一个1 多的就是最后一个位上的1
    // 偶数一定和除以2之后的数 1的个数相等， 因为只是右移一位 把最低位的0移除了而已
    vector<int> countBits(int n) {
        vector<int> dp(n + 1);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            if (i % 2 == 0) { // 偶数
                dp[i] = dp[i / 2];
            } else {
                dp[i] = dp[i - 1] + 1;
            }
        }
        return dp;
    }
};