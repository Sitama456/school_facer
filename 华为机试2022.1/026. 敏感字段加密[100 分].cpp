/**
 * @file 026. 敏感字段加密[100 分].cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief https://blog.csdn.net/weixin_37580235/article/details/125156696
 * 
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string spilitCommands(string& str) {
    int i = 0;
    vector<string> commands;
    int len = str.size();
    // 跳过开头的_
    while (i < len && str[i] == '-' ) {
        i++;
    }
    int j = i;
    while (i < len) {
        // 如果 str[i]是 " 就找到下一个"
        if (str[i] == '"') {
            while (i < len && str[i] != '"') {
                i++;
            }
            commands.push_back(str.substr(j, i - j + 1));
            i++;
            // 跳过分隔符
            while (i < len && str[i] == '_') {
                i++;
            }
            j = i;
        } else {
            // 跳过普通字符
            while (i < len && str[i] != '_') {
                i++;
            }
            commands.push_back(str.substr(j, i - j));
            // 跳过分隔符
            while (i < len && str[i] == '_') {
                i++;
            }
            j = i;
        }
        
    }
    // 处理给定的串
    // ...
    return "...";
}