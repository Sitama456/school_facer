/**
 * @file 10.斐波那契数列.h
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
 * 写一个函数，输入 n ，求斐波那契（Fibonacci）数列的第 n 项（即 F(N)）。斐波那契数列的定义如下：

F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
斐波那契数列由 0 和 1 开始，之后的斐波那契数就是由之前的两数相加而得出。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/fei-bo-na-qi-shu-lie-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */

#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    int fib(int n) {
        return fib1(n);
    }

    int fib1(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        int mod = pow(10, 9) + 7;
        vector<int> dp(n + 1);
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
            dp[i] = dp[i] % mod;
        }
        return dp[n];
    }
};