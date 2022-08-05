/**
 * @file 027. IPv4 地址转换成整数[100 分].cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief https://blog.csdn.net/weixin_37580235/article/details/125156897
 * 
 */

#include <vector>
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

vector<int> ipStrToNums(string& str) {
    vector<int> res;
    char *tmp = strtok((char*)str.data(), "#");
    while (tmp != NULL) {
        // 空串
        if (tmp[0] == '\0') {
            return {};
        }
        res.push_back(atoi(tmp));
    }
    return res;
}

int ipStrToNum(string& str) {
    vector<int> nums = ipStrToNums(str);
    int len = nums.size();
    if (len < 4) return -1;
    int res = 0;
    for (int i = 0; i < 4; ++i) {
        if (i == 0 && (nums[i] < 0 || nums[i] > 128)) {
            return -1;
        }
        if (nums[i] < 0 || nums[i] > 255) {
            return -1;
        }
        res = res * 256 + nums[i];
    }
    return res;
}