/**
 * @file 1. Manacher算法.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief Manacher算法 用 O(n)的复杂度找到str串中最长回文字串
 * (1) 经典解法，遍历每个位置，以这个位置为中心往外扩 取最大值。复杂度O(n^2)
 * 
 * (2) Manacher算法:
 * 概念 ： 
 * a ：回文直径与回文半径 2位置的
 *      #1#2#1#  回文直接为7 回文半径为4
 *      生成每个位置的回文半径，成为回文半径数组
 * b : 最右回文边界R。之前扩回文的过程中，达到的最右的位置
 * c : 最右回文边界对应的中心点 C。跟R配合使用
 * 算法开始：
 * (1) : 当来到一个位置i，此时i不在右边界里面，即 i > R。此时已i为中心，暴力扩。
 * (2) : 当来到一个位置i，此时i在最右回文边界内部，在内部 i <= R。 即存在这种关系  L ... I'... C ... I ... R
 *  A : I'的回文区域在 L ~ R 内部 此时 I 的回文半径与I'一样。可以手动画一下拓扑关系
 *  B : I'的回文区域，有部分已经跑到 L ~ R 外部。此时 I 的回文半径就是I ~ R。
 *  C : I'的回文区域压线L，I ~ R 一定是回文，有没有可能更远？继续往下扩
 * 
 */

#include <string>
#include <vector>
using namespace std;
// 返回回文字串长度 即直径
vector<int> manacher(string& s) {
    // 处理串 加特殊字符
    string str("#");
    for (char c : s) {
        str += c;
        str += '#';
    }
    int len = str.size();
    // Manacher 概念
    vector<int> pArr(len, 0); // 回文半径数组
    int R = -1; // 最右回文边界的再往右一个位置 最有的有效区域是 R - 1 位置
    int C = -1; // 最有回文边界时的中心

    // 求回文半径数组
    for (int i = 0; i < len; ++i) {
        
        int L = 2 * C - R;
        int i1 = 2 * C - i;
        // 至少不用验证的区域是 几个瓶颈中最痛的那个 几种情况都是
        pArr[i] = R > i ? min(pArr[i], R - i) : 1;
        // 从不需要验证的下一个需要验证的字符开始验证
        while (i + pArr[i] < len && i - pArr[i] >= 0) {
            if (str[i + pArr[i]] == str[i - pArr[i]]) {
                pArr[i]++;
            } else {
                break;
            }
        }
        // 如果更往右了
        if (i + pArr[i] > R) {
            R = i + pArr[i];
            C = i;
        }

    }
    vector<int> res(s.size(), 0);
    int count = 0;
    for (int i = 1; i < pArr.size(); i += 2) {
        res[count++] = pArr[i] - 1;
    }
    return res;

}
