/**
 * @file 033. 连续字母长度[100 分].cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief https://blog.csdn.net/weixin_37580235/article/details/125175034
 * 
 */

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int lengthOfKthLongStr(string& str, int k) {
    vector<int> lengths(26, 0);
    int len = str.size();
    int left = 0; // 左指针
    for (int i = 1; i < len; ++i) {
        if (str[i] != str[i - 1]) {
            int tmpLen = i - left;
            if (tmpLen > lengths[str[i - 1] - 'A']) {
                lengths[str[i - 1] - 'A'] = tmpLen;
            }
            left = i;
        } 
    }
    // 最后的字符
    int tmpLen = len - left;
    lengths[str[len - 1] - 'A'] = max(tmpLen, lengths[str[len - 1] - 'A']);
    // 排序
    sort(lengths.begin(), lengths.end(), greater<int>());
    if (k > lengths.size()) return -1;
    
    return lengths[k - 1] ? lengths[k - 1] : -1;
}

int main() {
    string inputStr;
    int k = 0;
    while (1) {
        cin >> inputStr;
        cin >> k;
        cout << lengthOfKthLongStr(inputStr, k) << endl;
    }
}