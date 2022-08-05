/**
 * @file 039. 数组组成的最小数字[100 分].cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief https://blog.csdn.net/weixin_37580235/article/details/125194165
 * 先选出数值最小的三个数 再使用贪心策略
 * 贪心策略 a b < b a
 * 
 */
#include <vector>
#include <string>
#include <string.h>
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int stringToInt(string numStr, int len) {
    int size = numStr.size();
    int count = len - size;
    int res = 0;
    for (int i = 0; i < size; ++i) {
        res = res * 10 + numStr[i] - '0';
    }
    return res;
}

bool cmp1(string a, string b) {
    int len1 = a.size();
    int len2 = b.size();
    int num1 = stringToInt(a, len1);
    int num2 = stringToInt(b, len2);
    return num1 < num2;
}

bool cmp2 (string a, string b) {
    string tmpA = a + b;
    string tmpB = b + a;
    int len = a.size() + b.size();
    int num1 = stringToInt(tmpA, len);
    int num2 = stringToInt(tmpB, len);
    return num1 < num2;
    
}

int minValue(vector<string>& nums) {
    // 先选出三个数再排序
    sort(nums.begin(), nums.end(), cmp1);
    vector<string> realStrs;
    int k = 3;
    int i = 0;
    while (i < nums.size() && k > 0) {
        realStrs.push_back(nums[i]);
        i++;
        k--;
    }

    sort(realStrs.begin(), realStrs.end(), cmp2);

    i = 0;
    string res;
    while (i < realStrs.size()) {
        res += realStrs[i];
        i++;
    }
    return stringToInt(res, res.size());
}

int main() {
    string inputStr;
    while (1) {
        cin >> inputStr;
        vector<string> numStr;
        char* tmp = strtok((char*)(inputStr.data()), ",");
        while (tmp != NULL) {
            numStr.push_back(tmp);
            tmp = strtok(NULL, ",");
        }
        cout << minValue(numStr) << endl;
    }
}