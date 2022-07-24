/**
 * @file HJ18 识别有效的IP地址和掩码并进行分类统计.cpp
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
请解析IP地址和对应的掩码，进行分类识别。要求按照A/B/C/D/E类地址归类，不合法的地址和掩码单独归类。

所有的IP地址划分为 A,B,C,D,E五类

A类地址从1.0.0.0到126.255.255.255;

B类地址从128.0.0.0到191.255.255.255;

C类地址从192.0.0.0到223.255.255.255;

D类地址从224.0.0.0到239.255.255.255；

E类地址从240.0.0.0到255.255.255.255


私网IP范围是：

从10.0.0.0到10.255.255.255

从172.16.0.0到172.31.255.255

从192.168.0.0到192.168.255.255


子网掩码为二进制下前面是连续的1，然后全是0。（例如：255.255.255.32就是一个非法的掩码）
（注意二进制下全是1或者全是0均为非法子网掩码）

注意：
1. 类似于【0.*.*.*】和【127.*.*.*】的IP地址不属于上述输入的任意一类，也不属于不合法ip地址，计数时请忽略
2. 私有IP地址和A,B,C,D,E类地址是不冲突的
 */

#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

vector<int> res(7, 0);
// 获取ip的4个数字段 如果不合法就为空
vector<int> getIpNum(string& ipStr) {
    vector<int> res;
    int count = 0;
    char* ptr = (char*)ipStr.c_str();
    char* tmp = strtok(ptr, ".");
    while (tmp != NULL) {
        if (count == 4) {
            res.clear();
            return res;
        }
        count++;
        res.push_back(atoi(tmp));
        tmp = strtok(NULL, ".");
    }
    return res;
}

// 判断是否是私网
bool isPrivateNet(vector<int>& ips) {
    if (ips[0] == 10) return true;
    if (ips[0] == 172 && ips[1] >= 16 && ips[1] <= 31) return true;
    if (ips[0] == 192 && ips[1] == 168) return true;
    return false;
}

// 判断掩码是否合法
bool isMask(vector<int>& ips) {
    unsigned int num = 0;
    for (int i = 0;  i < ips.size(); ++i) {
        num <<= 8;
        num |= ips[i];    
    }
    // 如果全是0或者全是1
    if (num == 0) return false;
    unsigned tmp = ~num;
    tmp += 1;
    if (tmp == 1) return false;
    // 如果不是连续的1和0
    // 先取反 + 1 在或上原来的值 如果相等则是合法的
    tmp |= num;
    return tmp == num;
}

void divide(vector<int>& ipNum) {
    if (ipNum[0] >= 1 && ipNum[0] <= 126) res[0]++;
    else if (ipNum[0] >= 128 && ipNum[0] <= 191) res[1]++;
    else if (ipNum[0] >= 192 && ipNum[0] <= 223) res[2]++;
    else if (ipNum[0] >= 224 && ipNum[0] <= 239) res[3]++;
    else if (ipNum[0] >= 240 && ipNum[0] <= 255) res[4]++;
}

int main(){
    string s;
    vector<int> ipNum;
    vector<int> maskNum;
    string ipStr;
    string maskStr;
    while (cin >> s) {
        int split = s.find('~');
        ipStr = s.substr(0, split);
        maskStr = s.substr(split + 1);
        ipNum = getIpNum(ipStr);
        maskNum = getIpNum(maskStr);
        if (ipNum.empty()) { // 错误的ip
            res[5]++;
            continue;
        }
        if (maskNum.empty() || !isMask(maskNum) && ipNum[0]) { // 错误的掩码
            res[5]++;
            continue;
        }
        if (isPrivateNet(ipNum)) {
            res[6]++;
        }
        divide(ipNum);
    }
    for (int i = 0; i < 6; ++i) {
        cout << res[i] << " ";
    }
    cout << res[6];

    return 0;
}