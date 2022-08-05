/**
 * @file 8.华为机试：最远足迹.cpp
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
 * 【编程题目 | 100分】最远足迹 [ 100 / 中等 ]

最远足迹
题目描述：
某探险队负责对地下洞穴进行探险。 探险队成员在进行探险任务时，随身携带的记录器会不定期地记录自身的坐标，但在记录的间隙中也会记录其他数据。 探索工作结束后，探险队需要获取到某成员在探险过程中相对于探险队总部的最远的足迹位置。

仪器记录坐标时，坐标的数据格式为(x,y)，如(1,2)、(100,200)，其中0<x<1000，0<y<1000。同时存在非法坐标，如(01,1)、(1,01)，(0,100)属于非法坐标。
设定探险队总部的坐标为(0,0)，某位置相对总部的距离为：x * x+ y * y。
若两个座标的相对总部的距离相同，则第一次到达的坐标为最远的足迹。
若记录仪中的坐标都不合法，输出总部坐标（0,0）。 备注：不需要考虑双层括号嵌套的情况，比如sfsdfsd((1,2))。
输入描述:
字符串，表示记录仪中的数据。

如：ferga13fdsf3(100,200)f2r3rfasf(300,400)

输出描述：
字符串，表示最远足迹到达的坐标。

如： (300,400)

示例 1：

输入
ferg(3,10)a13fdsf3(3,4)f2r3rfasf(5,10)
1
输出
(5,10)
1
说明
记录仪中的合法坐标有3个： (3,10)， (3,4)， (5,10)，其中(5,10)是相距总部最远的坐标， 输出(5,10)。

示例 2：

输入
asfefaweawfaw(0,1)fe
1
输出
(0,0)
1
说明
记录仪中的坐标都不合法，输出总部坐标(0,0)
————————————————
版权声明：本文为CSDN博主「小朱小朱绝不服输」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/weixin_44052055/article/details/123945932
 */

#include <string.h>
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;



int getRecordDistance(string str) {
    int pos = str.find(',');
    // 看是否有效
    string numStr1 = str.substr(0, pos);
    string numStr2 = str.substr(pos + 1);
    if (numStr1[0] == '0' || numStr2[0] == 0) return -1;
    int x = atoi(numStr1.c_str());
    int y = atoi(numStr2.c_str());
    return x * x + y * y;

}

string maxLenRecord(string& recordStr) {
    int len = recordStr.size();
    int i = 0;
    // 跳过开头无效字符
    while (i < len && recordStr[i] != '(') {
        i++;
    }
    int j = i;
    int max = 0;
    string maxRes;
    while (i < len) {
        // 跳过有效字符
        while (i < len && recordStr[i] != ')') {
            i++;
        }
        int distance = getRecordDistance(recordStr.substr(j + 1, i - j - 1));
        if (distance > max) {
            maxRes = recordStr.substr(j, i - j + 1);
        }
        // 跳过无效字符
        while (i < len && recordStr[i] != '(') {
            i++;
        }
        j = i;

    }
    if (maxRes.empty()) {
        return "(0,0)";
    }
    return maxRes;
}

int main(int argc, char* argv[]) {
    string inputStr;
    while (1) {
        cin >> inputStr;
        cout << maxLenRecord(inputStr) << endl;
    }
    return 0;
}