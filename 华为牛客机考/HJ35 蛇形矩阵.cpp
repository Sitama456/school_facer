/**
 * @file HJ35 蛇形矩阵.cpp
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
蛇形矩阵是由1开始的自然数依次排列成的一个矩阵上三角形。

例如，当输入5时，应该输出的三角形为：

1 3 6 10 15

2 5 9 14

4 8 13

7 12

11


输入描述：
输入正整数N（N不大于100）

输出描述：
输出一个N行的蛇形矩阵。
 */

#include <iostream>
#include <vector>
using namespace std;

void printMat(int N);
int main(){
    int N = 0;
    cin >> N;
    printMat(N);
    return 0;
}
int count = 1;
vector<vector<int>> mat;
void ZigPrintMat(int r1, int c1, int r2, int c2);
void printMat(int N) {
    mat.resize(N);
    for (int i = 0; i < N; ++i) {
        mat[i].resize(N - i);
    }
    for (int i = 0; i < N; ++i) {
        ZigPrintMat(0, i, i, 0);
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N - i; ++j) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    
}

// 定义从左下到右上打印的函数 
void ZigPrintMat(int r1, int c1, int r2, int c2) {
    // r1 c1 为右上角
    // r2 c2 为左下角
    // 从左下角到右上角打印
    while (r2 >= r1 && c2 <= c1) {
        mat[r2--][c2++] = count++;
    }
}