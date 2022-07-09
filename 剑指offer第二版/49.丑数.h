/**
 * @file 49.丑数.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 我们把只包含质因子 2、3 和 5 的数称作丑数（Ugly Number）。求按从小到大的顺序的第 n 个丑数。
 * 
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int nthUglyNumber(int n) {
        // 动态规划
        if (n == 1) return 1;
        vector<int> dp(n + 1);
        dp[1] = 1;
        int a = 1;
        int b = 1;
        int c = 1;
        // 丑数是由较小的丑数乘 2 3 5而来的
        // 为了防止漏掉，每个数都应该乘 2 3 5 然后再比较大小，但前面的哪个数乘2
        // 哪个数乘3，哪个数乘5呢? 
        // 所以用 a b c标记 a 之前的丑数都乘过2了，但乘没乘3和5不知道，b c同理。循环之后就
        // 前面的每个丑数都乘了 2 3 5 了。比如原始为 num = 1, a = b = c = 1;
        //  (num *= 2) = 2 : a = 2 b = c = 1
        // (num *= 2) = 4 : a = 3 b = c = 1
        // 但此时 num = 4, 4 * 2 < 2 * 3, 所以此时num 为 2 的丑数会乘一个3，并且这个数前面
        // 乘过2了。 所以 a b c只是标记前a b c 个数乘过2了

        for (int i = 2; i <= n; ++i) {
            int n2 = dp[a] * 2;
            int n3 = dp[b] * 3;
            int n5 = dp[c] * 5;
            dp[i] = min(n2, min(n3, n5));
            if (dp[i] == n2) a++;
            if (dp[i] == n3) b++;
            if (dp[i] == n5) c++;
        }
        return dp[n];
    }

};