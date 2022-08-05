/**
 * @file 6.华为机试：拼接URL.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 
 * 拼接URL
题目描述：
给定一个url前缀和url后缀,通过,分割 需要将其连接为一个完整的url
如果前缀结尾和后缀开头都没有/，需要自动补上/连接符
如果前缀结尾和后缀开头都为/，需要自动去重
约束：不用考虑前后缀URL不合法情况
输入描述:
url前缀(一个长度小于100的字符串) url后缀(一个长度小于100的字符串)

输出描述：
拼接后的url

示例 1：

输入
/acm,/bb
1
输出
/acm/bb
1
示例 2：

输入
/abc/,/bcd
1
输出
/abc/bcd
1
示例 3：

输入
/acd,bef
1
输出
/acd/bef
1
示例 4：

输入
,
1
输出
/
————————————————
版权声明：本文为CSDN博主「小朱小朱绝不服输」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/weixin_44052055/article/details/123960538
 */

#include <string>
#include <string.h>
#include <iostream>
using namespace std;

string getUrlBody(string url) {
    string res;
    for (char c : url) {
        if (c != '/') {
            res.push_back(c);
        }
    }
    return res;
}

string URLConnect(string pre, string next) {
    string URLpre = getUrlBody(pre);
    string URLnext = getUrlBody(next);
    string res;
    res += "/";
    res += URLpre;
    if (!URLpre.empty()) res += "/";
    res += URLnext;
    return res;
}

int main() {
    string inputStr;
    while (1) {
        cin >> inputStr;
        int pos = inputStr.find(',');
        string pre = inputStr.substr(0, pos);
        string next = inputStr.substr(pos + 1);
        cout << URLConnect(pre, next) << endl;
    }
    return 0;
}