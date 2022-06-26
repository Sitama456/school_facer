/**
 * @file 14.2剪绳子.h
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
 * 给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 k[0],k[1]...k[m - 1] 。请问 k[0]*k[1]*...*k[m - 1] 可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/jian-sheng-zi-ii-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */

/**
 * @brief 本题与上一题的区别是，模完一个数后，会影响 dp[i]的最大值的判断。比如 1000000008 > 1000000006 但是模完
 * p = 1000000007 后，前者反而小了
 * 
 */


class Solution {
public:
    int cuttingRope(int n) {
        // 由公式可知 (n1 + n2 + ... na) / a >= (n1 * n2 * ... * na) ^ (1 / a)
        // 当 n1 = n2 = ... = na 时等号成立
        // 所以应尽可能分成相等的段
        // 优先凑出长度为3的段

        // (1) 若是长度小于3 则分为 1 和 n - 1
        if(n <= 3) return n - 1;
        
        int b = n % 3, a = n / 3;
        int mod = 1000000007;
        // (2) 余数为 1 的情况需要拆一个 3 来组成 2 * 2 > 1 * 3
        int numberOfThree = b == 1 ? a - 1 : a;
        // 大数取余 即 3 ^ (numberOfThree) % p
        // 有可能会发生 4 * (mod - 1) 的情况， 会溢出 所以用long
        long res = bigNumMod1(3, numberOfThree, mod);
        if (b == 0) {
            return (int)res;
        }
        if (b == 1) {
            return (int)(res * 4 % mod);
        }
        // 余数为2 直接相乘
        return (int)(res * 2 % mod);
    }

    // 大数取余方法 避免溢出
    // (xy)⊙p=[(x⊙p)(y⊙p)]⊙p

    //1、循环取余法 假设 num = x ^ a 余数为 p 且 x < p
    //(x ^ a) % p = ((x ^ (a - 1)) % p * (x % p)) % p = (x ^ (a - 1) % p * x) %p
    
    // 1 < x < p
    int bigNumMod1(int x, int a, int p) {
        // res 代表 x ^ (a - 1) 
        long res = 1;  // x ^ 0 = 1 => 1 % p = 1
        for (int i = 0; i < a; ++i) {
            res = (res * x) % p;
        }
        return (int)res;
    }

    // 快速求余法
    // (x ^ a) % p = (x ^ 2) ^ (a / 2) % p = (x ^ 2 % p) ^ (a / 2) % p
    // 如果 a 是奇数 则
    // (x ^ a) % p = (x * x ^ a - 1) % p = [x * (x ^ 2 % p) ^ (a / 2)] % p
    int bigNumMod2(int x, int a, int p) {
        // res 代表 (x ^ 2 % p) ^ (a / 2) 
        long tmp = x;
        long res = 1;
        while (a > 0) {
            if (a % 2) {
                res = (tmp * res) % p;
            }
            tmp = (tmp * tmp) % p;
            a /= 2;
        }
        return (int)res;
    }

};