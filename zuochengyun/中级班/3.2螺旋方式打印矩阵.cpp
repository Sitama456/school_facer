/**
 * @file 3.2螺旋方式打印矩阵.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 以螺旋方式打印矩阵
 * 
 */

#include <vector>
#include <iostream>
using namespace std;

/**
 * @brief a b为左上角点    c d 为右下角点
 * 
 * @param a 
 * @param b 
 * @param c 
 * @param d 
 */
void printEdge(vector<vector<int>>& mat, int a, int b, int c, int d) {
    if (a == c) {
        for (int i = b; i <= d; ++i) {
            cout << mat[a][i] << " ";
        }

    } else if (b == d) {
        for (int i = a; i <= c; ++i) {
            cout << mat[i][b] << " ";
        }
    } else {
        int curC = b;
        int curR = a;
        while (curC != d) {
            cout << mat[curR][curC] << " ";
            curC++;
        }
        while (curR != c) {
            cout << mat[curR][curC] << " ";
            curR++;
        }
        while (curC != b) {
            cout << mat[curR][curC] << " ";
            curC--;
        }
        while (curR != a) {
            cout << mat[curR][curC] << " ";
            curR--;
        }
    }
}

void spiralOrderPrint(vector<vector<int>>& mat) {
    int tR = 0;
    int tC = 0;
    int dR = mat.size() - 1;
    int dC = mat[0].size() - 1;
    while (tR <= dR && tC <= dC) {
        printEdge(mat, tR++, tC++, dR--, dC--);
    }
}

/**
 * @brief 使用有限几个变量 是一个正方形矩阵顺时针转90度
 * 
 */

void rotateEdges(vector<vector<int>>& mat, int a, int b, int c, int d) {
    int n = d - b + 1;
    // 有几组数据需要交换
    int tmp = 0;
    for (int i = 0; i < n - 1; ++i) {
        tmp= mat[a][b + i];
        mat[a][b + i] = mat[c - i][b];
        mat[c - i][b]= mat[c][d - i];
        mat[c][d - i]= mat[a + i][d];
        mat[a + i][d] = tmp;


    }
}

void rotate(vector<vector<int>>& mat) {
    int tR = 0;
    int tC = 0;
    int dR = mat.size() - 1;
    int dC = mat[0].size() - 1;
    while (tR < dR) {
        rotateEdges(mat, tR++, tC++, dR--, dC--);
    }
}

/**
 * @brief zigzag 打印矩阵
 * 
 */

void zigzagPrintEdges(vector<vector<int>>& mat, int a, int b, int c, int d, bool flag) {
    if (flag) {
        while (a <= c) {
            cout << mat[a++][b--] << " ";
        }
    } else {
        while (a <= c) {
            cout << mat[c--][d++] << " ";
        }
    }
}

void printMatrixZigZag(vector<vector<int>> mat) {
    int ar = 0;
    int ac = 0;
    int br = 0;
    int bc = 0;
    bool flag = false;
    int endR = mat.size() - 1;
    int endC = mat[0].size() - 1;
    while (ar <= endR) {
        zigzagPrintEdges(mat, ar, ac, br, bc, flag);

        ar = ac == endC ? ar + 1 : ar;
        ac = ac == endC ? ac : ac + 1;
        bc = br == endR ? bc + 1 : bc;
        br = br == endR ? br : br + 1;
        flag = !flag;
    }
}