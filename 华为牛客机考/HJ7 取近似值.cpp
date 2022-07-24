/**
 * @file HJ7 取近似值.cpp
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
写出一个程序，接受一个正浮点数值，输出该数值的近似整数值。如果小数点后数值大于等于 0.5 ,向上取整；小于 0.5 ，则向下取整。

数据范围：保证输入的数字在 32 位浮点数范围内
输入描述：
输入一个正浮点数值

输出描述：
输出该数值的近似整数值
 */

#include <iostream>
using namespace std;

int main(){
    double num;
    cin >> num;
    int x = (int)num;
    if (num - x >= 0.5) {
        cout << x + 1;
    } else {
        cout << x;
    }
    return 0;
}