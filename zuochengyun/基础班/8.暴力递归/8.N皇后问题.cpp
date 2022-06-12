/**
 * @file 8.N皇后问题.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief N皇后问题是指在 N * N 的棋盘上要摆 N 个皇后，要求任何两个皇后不同行，不同列，
 * 也不在同一条斜线上。
 * 给定一个整数n,返回 n 皇后的摆法有多少种 
 * 
 */

#include <vector>
#include <math.h>
using namespace std;
/**
 * @brief 判断皇后间是否冲突
 * 
 * @param record 
 * @param i 
 * @param j 
 * @return true 
 * @return false 
 */
bool isValid(vector<int>& record, int i, int j) {
    for (int k = 0; k < i; ++k) {
        // 共列或共斜线
        if (j == record[k] || fabs(record[k] - j) == fabs(i - k)) {
            return false;
        }
    }
    return true;
}
/**
 * @brief i ~ n 行点皇后
 * 
 * @param i 
 * @param record 
 * @param n 
 * @return int 
 */
int process1(int i, vector<int>& record, int n) {
    // i 来到终止位置 则找到了一种点法
    if (i == n) {
        return 1;
    }
    int res = 0;
    // 来到 i 行 放在 j 列，会不会和之前的皇后 共行共列共斜线
    for (int j = 0; j < n; ++j) {
        if (isValid(record, i, j)) {
            // 皇后可以点在 j 列
            record[i] = j;
            res += process1(i + 1, record, n);
        }
    }
    return res;
}

int queueNum(int n) {
    if (n < 1) {
        return 0;
    }
    vector<int> record;
}
// todo 位运算加速 