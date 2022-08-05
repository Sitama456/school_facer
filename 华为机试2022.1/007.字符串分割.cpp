/**
 * @file 007.字符串分割.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief https://blog.csdn.net/weixin_37580235/article/details/125114401
 * 
 */
#include <string>
#include <vector>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;

string bitNum(char c) {
    string res;
    while (c) {
        res.push_back((c % 10) + '0');
        c /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

bool isValid(string s) {
    string bits;
    for (char c : s) {
        bits += bitNum(c);
        if (bits.size()) return false;
    }
    if (bits.size() != 3) return false;
    int num = 0;
    for (int i = 0; i < bits.size(); ++i) {
        num += pow(bits[i] - '0', 3);
    }
    return num == atoi(bits.c_str());
}

void spilit(string& str, int i, vector<string>& path, vector<vector<string>>& res) {
    if (i == str.size()) {
        res.push_back(path);
        return ;
    }
    for (int j = i; j < str.size(); ++j) {
        if (isValid(str.substr(i, j - i + 1))) {
            path.push_back(str.substr(i, j - i + 1));
            spilit(str, j + 1, path, res);
            path.pop_back();
        }
    }
}

int main() {
    string inputStr;
    while (1) {
        getline(cin, inputStr);
        vector<string> path;
        vector<vector<string>> res;
        spilit(inputStr, 0, path, res);
        if (res.empty()) {
            cout << 0;
        } else if (res.size() > 1) {
            cout << -1;
        } else {
            cout << res[0].size();
        }
    }
    

}