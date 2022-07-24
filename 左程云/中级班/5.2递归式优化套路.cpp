/**
 * @file 5.2递归式优化套路.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 除了初始项之外，后续所有项都严格满足某一个递推式，比如斐波那契数列 F(n) = F(n - 1) + F(n - 2)。
 * 求F(n)时可以做到log(n)的水平。
 * F(n) = F(n - 1) + F(n - 2) 二阶递推式 则 | | 代表矩阵
 * |F(3), F(2)| = |F(2), F(1)| * |a  b|
 *                               |c  d|
 * 
 * |F(4), F(3)| = |F(3), F(2)| * |a  b|
 *                               |c  d|
 * 
 * 可以利用初始的几项先求出 a b c d。则可以推出
 * |F(n), F(n - 1)| = |F(2), F(1)| * (|a  b|) ^ (n - 2)
 *                                   (|c  d|)
 * 
 * 问题转换到了求矩阵的某次方问题
 * 
 * 如何求n^m次方最快。快速幂方法
 * 1) 先将m拆成2的幂的和 比如 10 ^ (75) = 10 ^ (64 + 8 + 2 + 1)
 * 2) 先让t = 10 ^ 1次方。如果75的2进制位上为1，则 res *= t。 然后 t = t * t;
 * 
 * 矩阵同理
 */
#include <vector>
using namespace std;

vector<vector<int>> multiMatrix(vector<vector<int>>& m1, vector<vector<int>>& m2) {
    vector<vector<int>> result;
    return result;
}

vector<vector<int>> matrixPower(vector<vector<int>>& m, int p) {
    vector<vector<int>> res(m.size(), vector<int>(m[0].size(), 0)); // 单位阵
    for (int i = 0; i < m.size(); ++i) {
        res[i][i] = 1;
    }
    vector<vector<int>> t = m;
    for (; p != 0; p >> 1) {
        // 二进制位上为1
        if ((p & 1) != 0) {
            res = multiMatrix(res, t);
        }
        t = multiMatrix(t, t);
    }
    return res;

}

int fibo(int n) {
    if (n < 1) {
        return 0;
    }
    if (n == 1 || n == 2) {
        return 1;
    }  

    vector<vector<int>> base = {
        {1, 1},
        {1, 0}
    };
    vector<vector<int>> res = matrixPower(base, n - 2);
    return res[0][0] + res[1][0];
}