/**
 * @file 8.华为机试：单词搜索（找到它）.cpp
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
 * 【编程题目 |200分】 单词搜索【2021 H2, 2022 Q1,Q2 考试题】

题目描述
找到它是一个小游戏，你需要在一个矩阵中找到给定的单词。

假设给定单词 HELLOWORD，在矩阵中只要能找到 H->E->L->L->O->W->O->R->L->D连成的单词，就算通过。

注意区分英文字母大小写，并且您只能上下左右行走，不能走回头路。

输入描述
输入第 1 行包含两个整数 n、m (0 < n,m < 21) 分别表示 n 行 m 列的矩阵，

第 2 行是长度不超过100的单词 W (在整个矩阵中给定单词 W 只会出现一次)，

从第 3 行到第 n+2 行是指包含大小写英文字母的长度为 m 的字符串矩阵。

输出描述
如果能在矩阵中连成给定的单词，则输出给定单词首字母在矩阵中的位置(第几行 第几列)，

否则输出“NO”。

示例
输入
5 5
HELLOWORLD
CPUCY
EKLQH
CHELL
LROWO
DGRBC
1
2
3
4
5
6
7
输出
3 2
1
输入
5 5
HELLOWORLD
CPUCY
EKLQH
CHELL
LROWO
AGRBC
1
2
3
4
5
6
7
输出
NO
————————————————
版权声明：本文为CSDN博主「小朱小朱绝不服输」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/weixin_44052055/article/details/125857670
 */
#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool backtrack(vector<vector<char>>& mat, string& target, int i, int m, int n, vector<vector<bool>>& used) {
    if (i == target.size()) {
        return true;
    }
    if (mat[m][n] != target[i]) {
        return false;
    }

    int M = mat.size();
    int N = mat[0].size();
   
    bool res = false;
    vector<int> dx = { 0, 0, 1, -1 };
    vector<int> dy = { 1, -1, 0, 0 };
    for (int k = 0; k < 4; ++k) {
        int newX = m + dx[k];
        int newY = n + dy[k];
        if (newX >= M || newX < 0 || newY >= N || newY < 0 || used[newX][newY]) {
            continue;
        }
        used[newX][newY] = true;
        res |= backtrack(mat, target, i + 1, newX, newY, used);
        used[newX][newY] = false;
        if (res) return res;
    }
    return res;

}

vector<int> searchStr(vector<vector<char>>& mat, string& targetStr) {
    int m = mat.size();
    int n = mat[0].size();
    vector<vector<bool>> used(m, vector<bool>(n, false));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            used[i][j] = true;
            if (backtrack(mat, targetStr, 0, i, j, used)) {
                return {i + 1, j + 1};
            }
            used[i][j] = false;
        }
    }
    return {};
}

int main(int argc, char* argv[]) {
    string targetStr;
    int m = 0;
    int n = 0;
    while (1) {
        cin >> m;
        cin >> n;
        cin >> targetStr;
        vector<vector<char>> mat(m, vector<char>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> mat[i][j];
            }
        }
        vector<int> res = searchStr(mat, targetStr);
        if (res.empty()) cout << "NO" << endl;
        else cout << res[0] << " " << res[1] << endl;
    }
    return 0;
}