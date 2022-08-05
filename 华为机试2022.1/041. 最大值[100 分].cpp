/**
 * @file 041. 最大值[100 分].cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief https://blog.csdn.net/weixin_37580235/article/details/125194333
 * 贪心策略: a b < b a 则 a 在前头
 */

#include <string>
#include <string.h>
#include <vector>
#include <math.h>
#include <algorithm>
#include <iostream>
using namespace std;

int stringToInt(string numStr, int len) {
    int size = numStr.size();
    int count = len - size;
    int res = 0;
    for (int i = size - 1; i >= 0; --i) {
        res += (numStr[i] - '0') * pow(10, count++);
    }
    return res;
}

bool cmp(string a, string b) {
    int len = a.size() + b.size();
    string tmp1 = a + b;
    string tmp2 = b + a;
    return stringToInt(tmp1, len) > stringToInt(tmp2, len);
}

int maxValue(vector<string>& numStrs) {
    sort(numStrs.begin(), numStrs.end(), cmp);
    string maxValueStr;
    for (string& str : numStrs) {
        maxValueStr += str;
    }
    return stringToInt(maxValueStr, maxValueStr.size());
}

int main(int argc, char* argv[]) {
    string inputStr;
    while (1) {
        getline(cin, inputStr);
        vector<string> strs;
        char *tmp = strtok((char*)(inputStr.data()), " ");
        while (tmp != NULL) {
            strs.push_back(tmp);
            tmp = strtok(NULL, " ");
        }
        cout << maxValue(strs) << endl;
    }
    return 0;

}