/**
 * @file 8.华为机试：最大差.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 
 * 【编程题目 | 200分】最大差 [ 200 / 中等 ]

最大差
题目描述：
判断一组不等式是否满足约束并输出最大差

给定一组不等式，判断是否成立并输出不等式的最大差(输出浮点数的整数部分)， 要求：

1）不等式系数为double类型，是一个二维数组；

2）不等式的变量为int类型，是一维数组；

3）不等式的目标值为double类型，是一维数组；

4）不等式约束为字符串数组，只能是：“>”,“>=”,“<”,“<=”,“=”，例如,不等式组：

a11*x1+a12*x2+a13*x3+a14*x4+a15*x5<=b1;
 
a21*x1+a22*x2+a23*x3+a24*x4+a25*x5<=b2;
 
a31*x1+a32*x2+a33*x3+a34*x4+a35*x5<=b3;
1
2
3
4
5
最大差=max
{  (a11*x1+a12*x2+a13*x3+a14*x4+a15*x5-b1),  
 
(a21*x1+a22*x2+a23*x3+a24*x4+a25*x5-b2), 
 
(a31*x1+a32*x2+a33*x3+a34*x4+a35*x5-b3)  }，
1
2
3
4
5
6
类型为整数(输出浮点数的整数部分)

输入描述
1）不等式组系数(double类型)：

a11,a12,a13,a14,a15 a21,a22,a23,a24,a25 a31,a32,a33,a34,a35
1
2）不等式变量(int类型)：

x1,x2,x3,x4,x5
1
3）不等式目标值(double类型)：

b1,b2,b3
1
4）不等式约束(字符串类型):

<=,<=,<=
1
输入：

a11,a12,a13,a14,a15;

a21,a22,a23,a24,a25;

a31,a32,a33,a34,a35;

x1,x2,x3,x4,x5;

b1,b2,b3;

<=,<=,<=
1
2
3
4
5
6
7
8
9
10
11
输出描述
true 或者 false, 最大差

示例 1：
输入
2.3,3,5.6,7,6;11,3,8.6,25,1;0.3,9,5.3,66,7.8;1,3,2,7,5;340,670,80.6;<=,<=,<=
1
输出
false 458
1
说明
// 2.3   ×   1   +   3   ×   3   +   5.6   ×   2   +   7   ×   7   +   6   ×   5   -   340 = -238.5
// 11   ×   1   +   3   ×   3   +   8.6   ×   2   +   25   ×   7   +   5   ×   1   -   670 = -452.8
// 0.3   ×   1   +   9   ×   3   +   5.3   ×   2   +   66   ×   7   +   7.8   ×   5   -   80.6 = 458.3
1
2
3
前两个不满足条件，所以输出为false。
然后计算三个差值中的最大值，取整数部分
————————————————
版权声明：本文为CSDN博主「小朱小朱绝不服输」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/weixin_44052055/article/details/124064445
 */
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

bool satisfyConstraints(vector<double>& values, vector<double>& target, vector<string>&ops) {
    int size = values.size();
    bool res = true;
    for (int i = 0; i < size; ++i) {
        if (ops[i] == ">") {
            res = values[i] > target[i];
        } else if (ops[i] == ">=") {
            res = values[i] >= target[i];
        } else if (ops[i] == "<") {
            res = values[i] < target[i];
        } else if (ops[i] == "<=") {
            res = values[i] <= target[i];
        } else if (ops[i] == "=") {
            res = values[i] == target[i];
        }
        if (res == false) return false;
    }
    return res;
}

bool inequalityConstraints(vector<vector<double>>& a, vector<int>& x, 
        vector<double>& targets, vector<string>& ops, int& maxSub) {
    
    int m = a.size();
    int n = a[0].size();
    vector<double> values(m); // 左侧的值
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            values[i] += a[i][j] * x[j];
        }
    }
    bool flag = satisfyConstraints(values, targets, ops);
    double maxValue = __DBL_MIN__;
    for (int i = 0; i < m; ++i) {
        if (values[i] - targets[i] > maxValue) {
            maxValue = values[i] - targets[i];
        }
    }
    maxSub = (int)maxValue;
    return flag;

}

vector<string> decode(string str, string spilit) {
    vector<string> res;
    char* tmp = strtok((char *)(str.data()), spilit.c_str());
    while (tmp != NULL) {
        res.push_back(tmp);
        tmp = strtok(NULL, spilit.c_str());
    }
    return res;
}

void decode(string& str, vector<vector<double>>& a, vector<int>& x, vector<double>& target, vector<string>& ops) {
    // 寻找最后一个 ;
    vector<string> strs = decode(str, ";");
    int size = strs.size();

    ops = decode(strs[size - 1], ",");
    int m = ops.size();
    a.resize(m);
    int i = 0;
    for (; i < m; ++i) {
        vector<string> tmps = decode(strs[i], ",");
        for (string& num : tmps) {
            a[i].push_back(atof(num.c_str()));
        }
    }
    vector<string> xStr = decode(strs[i], ",");
    for (string& num : xStr) {
        x.push_back(atoi(num.c_str()));
    }
    i++;
    vector<string> targetStr = decode(strs[i], ",");
    for (string& num : targetStr) {
        target.push_back(atof(num.c_str()));
    }
    
}

int main(int argc, char* argv[]) {
    string inputStr;
    while (1) {
        vector<vector<double>> a;
        vector<int> x;
        vector<double> targets;
        vector<string> ops;
        cin >> inputStr;
        decode(inputStr, a, x, targets, ops);
        int maxValue = 0;
        cout << (bool)inequalityConstraints(a, x, targets, ops, maxValue) << " ";
        cout << maxValue << endl;
    }
    return 0;
} 