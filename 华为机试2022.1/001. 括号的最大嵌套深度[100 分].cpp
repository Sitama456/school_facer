/**
 * @file 001. 括号的最大嵌套深度[100 分].cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief https://blog.csdn.net/weixin_37580235/article/details/125110335
 * 
 */
#include <string>
using namespace std;
int maxDepth(string& s) {
    int count = 0;
    int res = 0;
    for (char c : s) {
        if (c == '(') {
            count++;
            res = max(count, res);
        } else if (c == ')') {
            count--;
        }
    }
    return res;
}