/**
 * @file 2.华为机试：完全二叉树非叶子部分后序遍历.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 
 * 【编程题目 | 200分】完全二叉树非叶子部分后序遍历 [ 200 / 中等 ]

完全二叉树非叶子部分后序遍历
题目描述：
给定一个以顺序储存结构存储整数值的完全二叉树序列（最多1000个整数），请找出此完全二叉树的所有非叶子节点部分，然后采用后序遍历方式将此部分树（不包含叶子）输出。

1、只有一个节点的树，此节点认定为根节点（非叶子）。

2、此完全二叉树并非满二叉树，可能存在倒数第二层出现叶子或者无右叶子的情况

其他说明：二叉树的后序遍历是基于根来说的，遍历顺序为：左-右-根

输入描述
一个通过空格分割的整数序列字符串

输出描述
非叶子部分树结构

示例 1：
输入
1 2 3 4 5 6 7
1
输出
2 3 1
1
说明
找到非叶子部分树结构，然后采用后序遍历输出
————————————————
版权声明：本文为CSDN博主「小朱小朱绝不服输」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/weixin_44052055/article/details/124107075
 */
#include <vector>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;

bool isLeaf(vector<int>& tree, int i) {
    return 2 * i + 1 >= tree.size() && 2 * i + 2 >= tree.size();
}

void dfs(vector<int>& tree, int i) {
    if (i >= tree.size()) return;
    if (isLeaf(tree, i)) return;
    int left = 2 * i + 1;
    int right = left + 1;
    dfs(tree, left);
    dfs(tree, right);
    cout << tree[i] << " ";
}

int main(int argc, char* argv[]) {
    string inputStr;
    while (1) {
        getline(cin, inputStr);
        char *tmp = strtok((char *)(inputStr.data()), " ");
        vector<int> tree;
        while (tmp != NULL) {
            tree.push_back(atoi(tmp));
            tmp = strtok(NULL, " ");
        }
        dfs(tree, 0);
        cout << endl;
    }
    return 0;
}