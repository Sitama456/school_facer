/**
 * @file 043.判断一组不等式是否满足约束并输出最大差[100 分].cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief https://blog.csdn.net/weixin_37580235/article/details/125361416
 * 字符串处理
 */

#include <vector>
#include <string>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

bool isMatched(double num, double target, string op) {
    if (op == ">") {
        return num > target;
    }
    if (op == ">=") {
        return num >= target;
    }
    if (op == "<") {
        return num < target;
    }
    if (op == "<=") {
        return num <= target;
    }
    if (op == "=") {
        return num == target;
    }
}

bool isSatifyConstraint(vector<vector<double>>& a, vector<int>& x, vector<double>& targets, vector<string>& ops
                    , int& maxValue) {
    int m = a.size();
    int n = a[0].size();
    vector<double> results(m, 0);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            results[i] += a[i][j] * x[j];
        }
    }
    bool flag = true;
    int maxVal = INT32_MIN;
    for (int i = 0; i < m; ++i) {
        if (!isMatched(results[i], targets[i], ops[i])) {
            flag = false;
        }
        maxVal = max(maxVal, (int)(results[i] - targets[i]));
    }
    maxValue = maxVal;
    return flag;
}

void decode(string& str, vector<vector<double>>& a, vector<int>& x, vector<double>& target, vector<string>& ops) {
    vector<string> strs;
    char* tmp = strtok((char *)(str.data()), ";");
    while (tmp != NULL) {
        strs.push_back(tmp);
        tmp = strtok(NULL, ";");
    }
    // 最后一组是不等式符号
    int size = strs.size();
    tmp = strtok((char *)(strs[size - 1].data()), ",");
    while (tmp != NULL) {
        ops.push_back(tmp);
        tmp = strtok(NULL, ",");
    }
    int i = 0;
    int m = ops.size(); // 不等式的个数
    a.resize(m);
    while (i < m) {
        tmp = strtok((char *)(strs[i].data()), ",");
        while (tmp != NULL) {
            a[i].push_back(atof(tmp));
            tmp = strtok(NULL, ",");
        }
        i++;
    }
    // 不等式变量
    tmp = strtok((char *)(strs[i].data()), ",");
    while (tmp != NULL) {
        x.push_back(atoi(tmp));
        tmp = strtok(NULL, ",");
    }
    // 不等式目标
    i++;
    tmp = strtok((char *)(strs[i].data()), ",");
    while (tmp != NULL) {
        target.push_back(atof(tmp));
        tmp = strtok(NULL, ",");
    }

}

int main(int argc, char* argv[]) {
    string inputStr;
    while (1) {
        cin >> inputStr;
        // ....
    }
    return 0;
}