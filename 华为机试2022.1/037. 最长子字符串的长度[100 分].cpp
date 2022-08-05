/**
 * @file 037. 最长子字符串的长度[100 分].cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief https://blog.csdn.net/weixin_37580235/article/details/125193876
 * 
 */
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int maxLengSubStr(string& str) {
    int count = 0;
    for (char c : str) {
        if (c == '0') {
            count++;
        }
    }
    if (count % 2 == 0) {
        return str.size();
    } else {
        // 因为是首尾相连的串 所以抛弃掉一个o就行了
        return str.size() - 1;
    }

}