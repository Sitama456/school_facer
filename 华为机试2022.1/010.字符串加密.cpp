/**
 * @file 010.字符串加密.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief https://blog.csdn.net/weixin_37580235/article/details/125116539
 * 
 */
#include <string>
#include <vector>
using namespace std;
void encode(string& str) {
    int len = str.size();
    vector<int> offsets { 1, 2, 4};
    if (len > 3) {
        offsets.resize(len);
    }
    for (int i = 3; i < len; ++i) {
        offsets[i] = offsets[i - 1] + offsets[i - 2] + offsets[i - 3];
    }
}