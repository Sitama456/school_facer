/**
 * @file HJ38 求小球落地5次后所经历的路程和第5次反弹的高度.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 
 * 描述
假设一个球从任意高度自由落下，每次落地后反跳回原高度的一半; 再落下, 求它在第5次落地时，共经历多少米?第5次反弹多高？


数据范围：输入的小球初始高度满足 1 \le n \le 1000 \1≤n≤1000  ，且保证是一个整数

输入描述：
输入起始高度，int型

输出描述：
分别输出第5次落地时，共经过多少米以及第5次反弹多高。
注意：你可以认为你输出保留六位或以上小数的结果可以通过此题
 */

#include<iostream>
using namespace std;

int main(){
    int N = 0;
    cin >> N;
    int time = 4;
    double res = N;
    double height = N;
    while (time--) {
        height /= 2;
        res += height * 2;
    }
    cout << res << endl;
    cout << height / 2;
    
}
