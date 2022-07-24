/**
 * @file HJ39 判断两个IP是否属于同一子网.cpp
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
 * 输入描述：
3行输入，第1行是输入子网掩码、第2，3行是输入两个ip地址
题目的示例中给出了三组数据，但是在实际提交时，你的程序可以只处理一组数据（3行）。

输出描述：
若IP地址或子网掩码格式非法则输出1，若IP1与IP2属于同一子网络输出0，若IP1与IP2不属于同一子网络输出2
 */

# include <iostream>
# include <string>
# include <vector>
using namespace std; 

vector<int> strToIpNum(string& ipStr);
bool isMask(vector<int>& mask);
void sameSubNet(vector<int>& ip1, vector<int>& ip2, vector<int>& mask);
int main(){
    string inputStr1;
    string inputStr2;
    string inputStr3;
    while (cin >> inputStr1) {
        cin >> inputStr2;
        cin >> inputStr3;
        vector<int> ip1, ip2, mask;
        ip1 = strToIpNum(inputStr2);
        ip2 = strToIpNum(inputStr3);
        mask = strToIpNum(inputStr1);
        if (ip1.empty() || ip2.empty() || mask.empty() || !isMask(mask)) {
            cout << 1 << endl;
            continue;
        }
        sameSubNet(ip1, ip2, mask);
    }
}

// 将str转为ip数字
vector<int> strToIpNum(string& ipStr) {
    int count = 0;
    vector<int> res;
    int i = 0;
    if (!isdigit(ipStr[i])) {
        return res;
    }
    int j = i;
    int len = ipStr.size();
    while (i < len) {
        if (res.size() > 4) return {};
        while (i < len && ipStr[i] != '.') {
            i++;
        }
        int num = atoi(ipStr.substr(j, i - j).c_str());
        if (num < 0 || num > 255) return {};
        res.push_back(num);
        while (i < len && ipStr[i] == '.') {
            i++;
        }
        j = i;
    }
    if (res.size() != 4) res.clear();
    return res;
}

void sameSubNet(vector<int>& ip1, vector<int>& ip2, vector<int>& mask) {
    for (int i = 0; i < ip1.size(); ++i) {
        ip1[i] &= mask[i];
        ip2[i] &= mask[i];
        if (ip1[i] != ip2[i]) {
            cout << 2 << endl;
            return;
        }
    }
    cout << 0 << endl;
    
}

bool isMask(vector<int>& mask) {
    int num = 0;
    for (int i = 0; i < mask.size(); ++i) {
        num <<= 8;
        num |= mask[i];
    }
    int help = ~num + 1;
    help |= num;
    return help == num;
}


