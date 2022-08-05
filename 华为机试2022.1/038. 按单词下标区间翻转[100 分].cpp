/**
 * @file 038. 按单词下标区间翻转[100 分].cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief https://blog.csdn.net/weixin_37580235/article/details/125194084
 * 
 */
#include <string>
#include <string.h>
#include <vector>
#include <iostream>
using namespace std;
vector<string> reverseStr(string str, int begin, int end) {
    vector<string> strs;
    char* tmp = strtok((char*)(str.data()), " ");
    while (tmp != NULL) {
        strs.push_back(tmp);
        tmp = strtok(NULL, " ");
    }
    int left = begin + (end - begin) / 2;
    int right = left;
    if ((end - begin) % 2 == 0) {
        right = left + 1;
    }
    while (left >= begin) {
        string tmp = strs[left];
        strs[left] = strs[right];
        strs[right] = tmp;
    }
    return strs;
}