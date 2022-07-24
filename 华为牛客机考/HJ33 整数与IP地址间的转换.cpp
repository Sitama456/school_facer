/**
 * @file HJ33 整数与IP地址间的转换.cpp
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
原理：ip地址的每段可以看成是一个0-255的整数，把每段拆分成一个二进制形式组合起来，然后把这个二进制数转变成
一个长整数。
举例：一个ip地址为10.0.3.193
每段数字             相对应的二进制数
10                   00001010
0                    00000000
3                    00000011
193                  11000001

组合起来即为：00001010 00000000 00000011 11000001,转换为10进制数就是：167773121，即该IP地址转换后的数字就是它了。

数据范围：保证输入的是合法的 IP 序列

输入描述：
输入 
1 输入IP地址
2 输入10进制型的IP地址

输出描述：
输出
1 输出转换成10进制的IP地址
2 输出转换后的IP地址
 */

#include<iostream>
#include<sstream>
#include<vector>
using namespace std;

long IpToInt(string& ip);
vector<int> intToIp(long num);
int main(){
    string inputStr;
    long num;
    cin >> inputStr;
    cin >> num;
    cout << IpToInt(inputStr) << endl;
    vector<int> ipNum = intToIp(num);
    for (int i = ipNum.size() - 1; i >= 1; --i) {
        cout << ipNum[i];
        cout << '.';
    }
    cout << ipNum[0];
}
bool isDigit(char c) {
    return c >= '0' && c <= '9';
}
long IpToInt(string& ip) {
    int len = ip.size();
    int i = 0;
    // 跳过无效的字符
    while (i < len && !isDigit(ip[i])) {
        i++;
    }
    int j = i;
    long res = 0;
    while (i < len && i < len) {
        // 跳过数字
        while (i < len && isDigit(ip[i])) {
            i++;
        }
        int num = atoi(ip.substr(j, i - j).c_str());
        res = res * 256 + num;
        // 跳过非数字
        while (i < len && !isDigit(ip[i])){
            i++;
        }
        j = i;
    }
    return res;
}

vector<int> intToIp(long num) {
    int mask = 255;
    vector<int> res;
    for (int i = 0; i < 4; ++i) {
        res.push_back(mask & num >> (i * 8));
    }
    return res;
}