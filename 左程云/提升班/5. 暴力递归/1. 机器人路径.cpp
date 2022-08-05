/**
 * @file 1. 机器人路径.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 给定一个整数 N。表示有 1 2 3 ... N 个位置
 * 给定一个整数 S 在 1 ~ N 之间 机器人起始位置
 * 给定一个整数 E 在 1 ~ N 之间 机器人终止位置
 * 给定一个整数 K 必须走K步。从 S 到达 E有多少种方法
 * 
 */

/**
 * @brief 
 * 
 * @param N 1 ~ N 这么多位置
 * @param E 目标是E
 * @param rest 还剩多少步要走
 * @param cur 当前位置
 * @return int 方法数
 */
int f (int N, int E, int rest, int cur) {
    if (rest == 0) {
        return cur == E ? 1 : 0;
    }
    // 还有路可以走
    // 只能往右走
    if (cur == 1) {
        return f(N, E, rest - 1, 2);
    }
    // 只能往左走
    if (cur == N) {
        return f(N, E, rest - 1, N - 1);
    }
    // 往左走 和 往右走
    return f(N, E, rest - 1, cur - 1) + f(N, E, rest - 1, cur + 1);
}

int walkWays(int N, int E, int S, int K) {
    return f(N, E, K, S);
}