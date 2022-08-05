/**
 * @file 4.华为机试：考古问题.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 
 * 【编程题目 | 200分】考古问题 [ 200 / 中等 ]

题目描述
考古问题，假设以前的石碑被打碎成了很多块，每块上面都有一个或若干个字符，请你写个程序来把之前石碑上文字可能的组合全部写出来，按升序进行排列。

示例
输入
3
a b c
1
2
输出
abc
acb
bac
bca
cab
cba
1
2
3
4
5
6
输入
3
a a b
1
2
输出
aab
aba
baa
————————————————
版权声明：本文为CSDN博主「小朱小朱绝不服输」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/weixin_44052055/article/details/125772120
 */

/**
 * @brief 无重复全排列
 * 
 */

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
void dfs(string& s, string& path, vector<string>& res, vector<bool>& used) {
    if (path.size() == s.size()) {
        res.push_back(path);
        return;
    }
    int size = s.size();
    for (int i = 0; i < size; ++i) {
        if (used[i]) {
            continue;
        }
        // 树层去重
        if (i > 0 && s[i] == s[i - 1] && used[i - 1] == false) {
            continue;
        }
        used[i] = true;
        path.push_back(s[i]);
        dfs(s, path, res, used);
        path.pop_back();
        used[i] = false;
    }
}

int main(int arge, char* argv[]) {
    char c;
    int n;
    while (1) {
        string inputStr;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> c;
            inputStr.push_back(c);
        }
        string path;
        vector<string> res;
        vector<bool> used(n, false);
        sort(inputStr.begin(), inputStr.end());
        dfs(inputStr, path, res, used);
        for (string& s : res) {
            cout << s << endl;
        }
    }
    return 0;
}