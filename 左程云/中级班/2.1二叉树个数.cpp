/**
 * @file 2.1二叉树个数.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 给定节点个数 n ，返回能形成的不同的二叉树的个数
 * 
 */
int process(int n) {
    if (n < 0) {
        return 0;
    }
    if (n == 0 || n == 1) {
        return 1;
    }
    if (n == 2) {
        return 2;
    }
    int res = 0;
    for (int leftNum = 0; leftNum <= n - 1; ++leftNum) {
        // 左树有leftNum个节点有多少种
        int leftWays = process(leftNum);
        // 头节点占了一个节点
        int rightWays = process(n - 1 - leftNum);
        res += leftWays * rightWays;
    }
    return res;
}