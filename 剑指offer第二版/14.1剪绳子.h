/**
 * @file 14.1剪绳子.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 k[0],k[1]...k[m-1] 。请问 k[0]*k[1]*...*k[m-1] 可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/jian-sheng-zi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include <vector>
using namespace std;
class Solution {
public:
    int cuttingRope(int n) {
        return dpMethod(n);
    }

    // n 长度的绳子的最大乘积
    int process(int n) {
        if (n == 1 || n == 2) {
            return 1;
        }
        if (n == 0) {
            return 0;
        }
        int res = 0;
        int num1 = 0;
        int num2 = 0;
        for (int i = 1; i <= n; ++i) {
            // 注意这里有一个选择 这个选择就是只剪成两段
            // 不剪下一段
            num1 = i * (n - i);
            // 剪掉下一段
            num2 = i * process(n - i);
            res = max(res, max(num1, num2));
        }
        return res;
    }

    int dpMethod(int n) {
        if (n == 1 || n == 2) return 1;
        vector<int> dp(n + 1);
        dp[1] = dp[2] = 1;
        for (int i = 3; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
            }
        }
        return dp[n];
    }

    // 大数取余方法 避免溢出
    // (xy)⊙p=[(x⊙p)(y⊙p)]⊙p

    //1、循环取余法 假设 num = x ^ a 余数为 p 且 x < p
    //(x ^ a) % p = ((x ^ (a - 1)) % p * (x % p)) % p = (x ^ (a - 1) % p * x) %p
    
    // 1 < x < p
    int bigNumMod1(int x, int a, int p) {
        // res 代表 x ^ (a - 1) 
        int res = 1;  // x ^ 0 = 1 => 1 % p = 1
        for (int i = 0; i < a; ++i) {
            res = (res * x) % p;
        }
        return res;
    }

    // 快速求余法
    // (x ^ a) % p = (x ^ 2) ^ (a / 2) % p = (x ^ 2 % p) ^ (a / 2) % p
    // 如果 a 是奇数 则
    // (x ^ a) % p = (x * x ^ a - 1) % p = [x * (x ^ 2 % p) ^ (a / 2)] % p
    int bigNumMod2(int x, int a, int p) {
        int res = 1;
        while (a > 0) {
            if (a % 2) {
                res = (x * res) % p;
            } 
            x = (x * x) % p;
            a /= 2;
        }
        
    }
};