/**
 * @file HJ15 求int型正整数在内存中存储时1的个数.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 
 * 描述
输入一个 int 型的正整数，计算出该 int 型数据在内存中存储时 1 的个数。

数据范围：保证在 32 位整型数字范围内
输入描述：
 输入一个整数（int类型）

输出描述：
 这个数转换成2进制后，输出1的个数
 */

#include<bitset>
#include<iostream>
using namespace std;

int main(){
    int num = 0;
    cin >> num;
    int count = 0;
    while (num) {
        if (num & 1) {
            count++;
        }
        num >>= 1;
    }
    cout << count;
}