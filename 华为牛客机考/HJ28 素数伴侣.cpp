/**
 * @file HJ28 素数伴侣.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 匈牙利算法 适用于2分图 即图被分为两个集合，求最大匹配个数
 * 算法学习笔记(5)：匈牙利算法 - Pecco的文章 - 知乎
    https://zhuanlan.zhihu.com/p/96229700
 * 
 * 描述
题目描述
若两个正整数的和为素数，则这两个正整数称之为“素数伴侣”，如2和5、6和13，它们能应用于通信加密。现在密码学会请你设计一个程序，从已有的 N （ N 为偶数）个正整数中挑选出若干对组成“素数伴侣”，挑选方案多种多样，例如有4个正整数：2，5，6，13，如果将5和6分为一组中只能得到一组“素数伴侣”，而将2和5、6和13编组将得到两组“素数伴侣”，能组成“素数伴侣”最多的方案称为“最佳方案”，当然密码学会希望你寻找出“最佳方案”。

输入:

有一个正偶数 n ，表示待挑选的自然数的个数。后面给出 n 个具体的数字。

输出:

输出一个整数 K ，表示你求得的“最佳方案”组成“素数伴侣”的对数。


数据范围： 1 \le n \le 100 \1≤n≤100  ，输入的数据大小满足 2 \le val \le 30000 \2≤val≤30000 
输入描述：
输入说明
1 输入一个正偶数 n
2 输入 n 个整数

输出描述：
求得的“最佳方案”组成“素数伴侣”的对数。
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int getMaxPrimeNumPair(vector<int>& odds, vector<int>& evens);
int main() {
    int n = 0;
    cin >> n;
    int num = 0;
    vector<int> odds; // 奇数集合
    vector<int> evens; // 偶数集合
    // 将输入分为奇数和偶数
    while (n--) {
        cin >> num; 
        if (num % 2 != 0) {
            odds.push_back(num);
        } else {
            evens.push_back(num);
        }
        
    } 
    if (odds.empty() || evens.empty()) {
        cout << 0;
        return 0;
    }
    cout << getMaxPrimeNumPair(odds, evens);
    return 0;
    
}
bool isPrimeNum(int x) {
    int limit = sqrt(x);
    for (int i = 2; i <= limit; ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}
/**
 * @brief 左边第 i 个位置能否匹配上
 * 
 * @param i  左边集合的索引
 * @param pairs 已经建立联系的图
 * @param p 右边集合元素的匹配信息
 * @param visit 在本轮匹配中已经访问过的右边元素 
 * @return true 
 * @return false 
 */
bool match(int i, vector<vector<int>>& pairs, vector<int>& p, vector<bool>& visit) {
    int N = pairs[0].size();
    for (int j = 0; j < N; ++j) {
        // 如果确实有联系 并且没有访问过
        if (pairs[i][j] && !visit[j]) {
            visit[j] = 1;
            // 要么p[j] == -1 没有决定配对
            // 要么p[j] >= 1 已经有配对了 尝试将给原配分配新的右边集合的配对
            // 成功则修改配对 失败则不改变配对关系
            if (p[j] == -1 || match(p[j], pairs, p, visit)) {
                p[j] = i;
                return true;
            }
        }
    }
    // 转了一圈 也没有找到配对
    return false;
}

int getMaxPrimeNumPair(vector<int>& odds, vector<int>& evens) {
    // 先建立二分图的连接
    int M = odds.size();
    int N = evens.size();
    // allPairs[i][j] 表示odds[i] + evens[j] 符合条件
    vector<vector<int>> allPairs(M, vector<int>(N, 0));
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (isPrimeNum(odds[i] + evens[j])) {
                allPairs[i][j] = 1;
            }
        }
    }
    // 寻找最大匹配数量
    int count = 0;
    vector<int> p(N, -1); // 右边集合中元素对于匹配的左边集合元素
    vector<bool> visit(N, false); // 查看标记 
    for (int i = 0; i < M; ++i) {
        // 每一轮清除标志位
        for (int i = 0; i < N; ++i) { visit[i] = false; }
        if (match(i, allPairs, p, visit)) {
            // 找到一个配对关系了
            count++;
        }
    }
    return count;
    
}