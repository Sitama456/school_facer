/**
 * @file 3.华为机试：字符串统计（全量和占用字符集）.cpp
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
 * 字符串统计（全量和占用字符集）
题目描述：
给定两个字符集合， 一个是全量字符集， 一个是已占用字符集， 已占用字符集中的字符不能再使用， 要求输出剩余可用字符集。

输入描述:
输入一个字符串 一定包含@，@前为全量字符集 @后的为已占用字符集
已占用字符集中的字符，一定是全量字符集中的字符，字符集中的字符跟字符之间使用英文逗号隔开
每个字符都表示为字符+数字的形式，用英文冒号分隔，比如a:1标识一个a字符
字符只考虑英文字母，区分大小写，数字只考虑正整型 不超过100
如果一个字符都没被占用，@标识仍存在
输出描述:
输出可用字符集，
不同的输出字符集之间用回车换行，
注意：输出的字符顺序要跟输入的一致，不能输出b:3,a:2,c:2
如果某个字符已全部占用，则不需要再输出
示例 1：

输入
a:3,b:5,c:2@a:1,b:2
1
输出
a:2,b:3,c:2
1
说明：
全量字符集为三个a，5个b，2个c
已占用字符集为1个a，2个b
由于已占用字符不能再使用
因此剩余可用字符为2个a，3个b，2个c
示例 2：

输入
a:3,b:5,c:2@
1
输出
a:3,b:5,c:2@
————————————————
版权声明：本文为CSDN博主「小朱小朱绝不服输」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/weixin_44052055/article/details/123926523
 */

#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

struct charAndCount {
    char c;
    int count = 0;
};

// op 0 : + 操作
// op 1 : -操作
vector<char> decodeStr(string str, map<char, int>& count, int op) {
    char *tmp = strtok((char*)(str.data()), ",");
    string tmps;
    vector<char> res;
    while (tmp != NULL) {
        tmps = tmp;
        int pos = tmps.find(':');
        res.push_back(tmps[0]);
        if (op == 0) count[tmps[0]] += atoi(tmps.substr(pos + 1).c_str());
        else if (op == 1) count[tmps[0]] -= atoi(tmps.substr(pos + 1).c_str());
        tmp = strtok(NULL, ",");
    }
    return res;
}

string usableChars(string& inputStr) {
    int spilitPos = inputStr.find('@');
    string allCharStr = inputStr.substr(0, spilitPos);
    string usedCharStr = inputStr.substr(spilitPos + 1);
    if (usedCharStr.empty()) {
        return allCharStr;
    }
    map<char, int> counts;
    vector<char> out = decodeStr(allCharStr, counts, 0);
    decodeStr(usedCharStr, counts, 1);
    string res;
    for (char c : out) {
        if (counts[c] > 0) {
            res += c;
            res += ":";
            res += to_string(counts[c]);
            res += ',';
        }
    }
    // 弹出最后一个','
    if (!res.empty()) res.pop_back();
    return res;
}

int main(int argc, char* argv[]) {
    string inputStr;
    while (1) {
        cin >> inputStr;
        cout << usableChars(inputStr) << endl;
    }
    return 0;
}