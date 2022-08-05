/**
 * @file 028. 考古学家[200 分].cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief https://blog.csdn.net/weixin_37580235/article/details/125175572
 * 
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void process(string& str, int i, string& path, vector<string>& res, vector<bool>& used) {
    if (i == str.size()) {
        res.push_back(path);
        return;
    }

    for (int i = 0; i < str.size(); ++i) {
        if (used[i]) {
            continue;
        }
        used[i] = true;
        path.push_back(str[i]);
        process(str, i + 1, path, res, used);
        path.pop_back();
        used[i] = false;
    }
}