/**
 * @file 2. KMP算法.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief KMP算法解决问题: 字符串str1和str2是否包含str2，如果包含str2在str1中开始的位置，如何做到时间复杂度
 * O(N)完成
 * 暴力解法: 尝试str1每一个开头能否配出str2来  O(N * M)
 * KMP:
 * 最长前后缀相等长度next 数组。i 位置的信息与str1[i]没有关系，与0 ~ i - 1有关系。记录最长的相等的前缀和后缀的长度。
 * 前缀不包含最后一个信息，后缀不包括第一个数组，即不取到整体。根据str2求的(较短的那个) 前缀和后缀都是从左到右
 * 认为规定 0 位置为-1。1位置为0
 * 加速过程：
 * str1 :   i ...  x ...
 * str2 :   0 ...  y ...
 * 假设一路都相等，假设到x，y位置时不相等。经典过程只能是 str1 i + 1位置 与 str2 0 位置相比。由next数组可知最大
 * 匹配长度 有 
 * str1 : i ... ...    z ... e x
 * str2 : 0 ... a .... b ... c y  ： 0 ~ a 与 b ~ c 相等 这里最好画图理解
 * 尝试以z位置开头尝试匹配出str2。又因为 z ~ e = b ~ c = 0 ~ a。所以从x位置与a下一个位置开始配
 * i ~ z中间开头一定配不出str2。证明： 假设从str1 从k位置开头能配出str2
 * str1 : i ... ... k ...  z ... e x 
 * str2 : 0 ... a ..l ...  b ....c y 此时k ~ e = l ~ c。又因为能配出str2则
 *                  0 ... ...    h .. 此时 k ~ e = 0 ~ h。所以 0 ~ h = l ~ c。相当于y之前的前后缀相等长度
 * 更长了。所以不可能。
 * 
 * 如果又不相等了，则str2继续往右推。推到不能再推了，则x往右移一格
 */
#include <string>
#include <vector>
using namespace std;
vector<int> getNextArr(string& s);
int find(string& str1, string& str2) {
    int i1 = 0; 
    int i2 = 0;
    vector<int> next = getNextArr(str2);
    while (i1 < str1.size() && i2 < str2.size()) {
        if (str1[i1] == str2[i2]) {
            i1++;
            i2++;
        } else if (i2 == 0) { // next[i2] == -1
            // 此时匹配不出了 i1跳下一个 即主串换一个开头
            i1++;
        } else {
            i2 = next[i2];
        }
    }
    // i1越界或者i2越界
    // i2越界说明配出str2了
    return i2 == str2.size() ? i1 - str2.size() : -1;
}

vector<int> getNextArr(string& s) {
    int len = s.size();
    vector<int> res(len, 0);
    res[0] = -1;
    res[1] = 0;
    int i = 2;
    // 哪个位置的字符与i-1的字符比 也代表当前使用位置的信息
    int cn = 0;
    while (i < res.size()) {
        if (s[i - 1] == s[cn]) {
            res[i++] = ++cn;
        } else if (cn > 0) {
            cn = res[cn];
        } else { // 跳不下去
            res[i++] = 0;
        }
    }
}