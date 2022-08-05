/**
 * @file 7.华为机试：矩阵最大值.cpp
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
 * 【编程题目 | 100分】矩阵最大值 [ 100 / 中等 ]

矩阵最大值
题目描述：
给定一个仅包含0和1的N*N二维矩阵，请计算二维矩阵的最大值，计算规则如下：

每行元素按下标顺序组成一个二进制数（下标越大越排在低位），二进制数的值就是该行的值。矩阵各行值之和为矩阵的值。
允许通过向左或向右整体循环移动每行元素来改变各元素在行中的位置。 比如：
[1,0,1,1,1]向右整体循环移动2位变为[1,1,1,0,1]，二进制数为11101，值为29。
[1,0,1,1,1]向左整体循环移动2位变为[1,1,1,1,0]，二进制数为11110，值为30。
输入描述:
输入的第一行为正整数，记录了N的大小，0 < N <= 20。
输入的第2到N+1行为二维矩阵信息，行内元素半角逗号分隔。
输出描述：
矩阵的最大值。

示例 1：

输入
5
1,0,0,0,1
0,0,0,1,1
0,1,0,1,0
1,0,0,1,1
1,0,1,0,1
1
2
3
4
5
6
输出
122
1
说明：
第一行向右整体循环移动1位，得到本行的最大值[1,1,0,0,0]，二进制为11000，十进制为24。
第二行向右整体循环移动2位，得到本行的最大值[1,1,0,0,0]，二进制为11000，十进制为24。
第三行向左整体循环移动1位，得到本行的最大值[1,0,1,0,0]，二进制为10100，十进制为20。
第四行向右整体循环移动2位，得到本行的最大值[1,1,1,0,0]，二进制为11100，十进制为28。
第五行向右整体循环移动1位，得到本行的最大值[1,1,0,1,0]，二进制为11010，十进制为26。
总和为24+24+20+28+26=122。
————————————————
版权声明：本文为CSDN博主「小朱小朱绝不服输」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/weixin_44052055/article/details/123944693
 */

#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;


int getValue(string bitStr, int start) {
    int len = bitStr.size();
    int res = 0;
    for (int i = len - 1; i >= 0; --i) {
        if (bitStr[i] == '1') {
            res += 1 << start;
        }
        start++;
    }
    return res;
}
/**
 * @brief 循环每一个为1的bit,让它作为最高位
 * 
 * @param bitStr 
 * @return int 
 */
int getMaxValue(string bitStr) {
    int len = bitStr.size();
    int maxValue = 0;
    for (int i = 0; i < len; ++i) {
        if (bitStr[i] == '1') {
            // 右端部分
            int right = getValue(bitStr.substr(i + 1), i);
            // 左端部分
            int left = getValue(bitStr.substr(0, i), 0);
            maxValue = max(maxValue, (1 << (len - 1)) + right + left); 
        }
    }
    return maxValue;
}

int matrixMaxValue(vector<string>bitStrArr) {
    int res = 0;
    for (int i = 0; i < bitStrArr.size(); ++i) {
        res += getMaxValue(bitStrArr[i]);
    }
    return res;
}

int main(int argc, char* argv[]) {
    int n = 0;
    string inputStr;
    while (1) {
        cin >> n;
        vector<string> bitStrArr(n);
        for (int i = 0; i < n; ++i) {
            cin >> inputStr;
            char* tmp = strtok((char*)(inputStr.data()), ",");
            while (tmp != NULL) {
                bitStrArr[i].push_back(tmp[0]);
                tmp = strtok(NULL, ",");
            }
        }
        cout << matrixMaxValue(bitStrArr) << endl;
    }
    return 0;
}