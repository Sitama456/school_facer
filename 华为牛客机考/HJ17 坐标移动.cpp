/**
 * @file HJ17 坐标移动.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 
 * 描述
开发一个坐标计算工具， A表示向左移动，D表示向右移动，W表示向上移动，S表示向下移动。从（0,0）点开始移动，从输入字符串里面读取一些坐标，并将最终输入结果输出到输出文件里面。

输入：

合法坐标为A(或者D或者W或者S) + 数字（两位以内）

坐标之间以;分隔。

非法坐标点需要进行丢弃。如AA10;  A1A;  $%$;  YAD; 等。

下面是一个简单的例子 如：

A10;S20;W10;D30;X;A1A;B10A11;;A10;

处理过程：

起点（0,0）

+   A10   =  （-10,0）

+   S20   =  (-10,-20)

+   W10  =  (-10,-10)

+   D30  =  (20,-10)

+   x    =  无效

+   A1A   =  无效

+   B10A11   =  无效

+  一个空 不影响

+   A10  =  (10,-10)

结果 （10， -10）

数据范围：每组输入的字符串长度满足 1\le n \le 10000 \1≤n≤10000  ，坐标保证满足 -2^{31} \le x,y \le 2^{31}-1 \−2 
31
 ≤x,y≤2 
31
 −1  ，且数字部分仅含正数
输入描述：
一行字符串

输出描述：
最终坐标，以逗号分隔
 */

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <string.h>
using namespace std;


vector<int> op(string& s) {
    vector<int> res(2);
    if (s.size() <= 1) return res;
    int size = s.size();
    int num = 0;
    for (int i = 1; i < size; ++i) {
        if (s[i] < '0' || s[i] > '9') {
            return res;
        }
        num = num * 10 + s[i] - '0';
    }
    if (s[0] == 'A') { // 左移动
        res[0] = -num;
    } else if (s[0] == 'W') { // 上
        res[1] = num;
    } else if (s[0] == 'D') { // 右
        res[0] = num;
    } else if (s[0] == 'S') {
        res[1] = -num;
    }
    return res;
}


vector<int> finalLoc(vector<string>& ops) {
    vector<int> res(2, 0);
    for (string& s : ops) {
        vector<int> move = op(s);
        res[0] += move[0];
        res[1] += move[1];
    }
    return res;
}

int main(){
    char str[10001];
    cin.getline(str, 10001);
    vector<string> strs;
    char* tmp = strtok(str, ";");
    while (tmp != NULL) {
        strs.push_back(tmp);
        tmp = strtok(NULL, ";");
    }
    vector<int> res = finalLoc(strs);
    cout << res[0] << "," << res[1];
    return 0;
    
}

