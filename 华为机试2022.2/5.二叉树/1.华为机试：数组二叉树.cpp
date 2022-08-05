/**
 * @file 1.华为机试：数组二叉树.cpp
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
 * 【编程题目 | 200分】数组二叉树 [ 200 / 中等 ]

数组二叉树
题目描述：
二叉树也可以用数组来存储，给定一个数组，树的根节点的值存储在下标1，对于存储在下标N的节点，它的左子节点和右子节点分别存储在下标2N和2N+1，并且我们用值-1代表一个节点为空。

给定一个数组存储的二叉树，试求从根节点到最小的叶子节点的路径，路径由节点的值组成。

输入描述
输入一行为数组的内容，数组的每个元素都是正整数，元素间用空格分隔。
注意第一个元素即为根节点的值，即数组的第N个元素对应下标N，下标0在树的表示中没有使用，所以我们省略了。
输入的树最多为7层。
输出描述
输出从根节点到最小叶子节点的路径上，各个节点的值，由空格分隔，用例保证最小叶子节点只有一个。

示例 1：
输入
3 5 7 -1 -1 2 4
1
输出
3 7 2
1
说明
最小叶子节点的路径为3 7 2

示例 2：
输入
5 9 8 -1 -1 7 -1 -1 -1 -1 -1 6
1
输出
5 8 7 6
1
说明
最小叶子节点的路径为5 8 7 6，注意数组仅存储至最后一个非空节点，故不包含节点“7”右子节点的-1
————————————————
版权声明：本文为CSDN博主「小朱小朱绝不服输」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/weixin_44052055/article/details/124078351
 */

/**
 * @brief 深度优先遍历
 * 
 */

#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;

bool isLeaf(vector<int>& tree, int i) {
    int size = tree.size();
    return (2 * i >= size || tree[2 * i] == -1) && (2 * i + 1 >= size || tree[2 * i + 1] == -1);
}

int dfs(vector<int>& tree, int i) {
    // 空节点
    if (i >= tree.size() || tree[i] == -1) return -1;
    int left = 2 * i;
    int right = left + 1;
    // 如果是叶子节点
    if (isLeaf(tree, i)) return i;
    // 左边节点
    int leftLeaf = dfs(tree, left);
    int rightLeaf = dfs(tree, right);
    if (leftLeaf == -1 && rightLeaf != -1) {
        return rightLeaf;
    } else if (leftLeaf != -1 && rightLeaf == -1) {
        return leftLeaf;
    } else if (leftLeaf != -1 && rightLeaf != -1) {
        return tree[leftLeaf] < tree[rightLeaf] ? leftLeaf : rightLeaf;
    } else {
        return leftLeaf;
    }

}


vector<int> minLeafNodePath(vector<int>& tree) {
    // 寻找最小叶子节点的索引
    int minLeafIndex = dfs(tree, 1);
    // 获取叶子节点父亲节点
    vector<int> res;
    while (minLeafIndex > 0) {
        res.push_back(tree[minLeafIndex]);
        minLeafIndex /= 2;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main(int argc, char* argv[]) {
    string inputStr;
    while (1) {
        getline(cin, inputStr);
        char* tmp = strtok((char*)(inputStr.data()), " ");
        vector<int> tree;
        tree.push_back(-1);
        while (tmp != NULL) {
            tree.push_back(atoi(tmp));
            tmp = strtok(NULL, " ");
        }
        vector<int> path = minLeafNodePath(tree);
        for (int i = 0; i < path.size(); ++i) {
            cout << path[i] << " ";
        }
        cout << endl;
    }
    return 0;
}