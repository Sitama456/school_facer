/**
 * @file 5.二叉树序列化和反序列化.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-05-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 二叉树的序列化与反序列化
 * 就是内存里的一棵树如果变成字符串形式，又如何从字符串形式变成内存里的树
 * 如何判断一颗树是不是另一棵树的子树
 * 
 */
#include <string>
#include <vector>
#include <queue>
using namespace std;
struct TreeNode
{
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) : value(value), left(nullptr), right(nullptr) {}
};

/**
 * @brief 字符串序列化 #代表空节点 先序方式序列化
 * 
 * @param root 
 */
string TreeSerializeByPre(TreeNode* root) {
    if (root = nullptr) {
        return "#_";
    }
    string res = to_string(root->value) + "_";
    res += TreeSerializeByPre(root->left);
    res += TreeSerializeByPre(root->right);
    return res;
}
vector<string> split(string& str, char c) {

}


TreeNode* TreeDeserializeByPre(vector<string> treeStr, int i) {
    if (treeStr[i] == "#") {
        return nullptr;
    }
    TreeNode* head = new TreeNode(atoi(treeStr[i].c_str()));
    head->left = TreeDeserializeByPre(treeStr, i + 1);
    head->right = TreeDeserializeByPre(treeStr, i + 2);
    return head;

}

TreeNode* TreeDeserializeByPre(string& treeStr) {
    vector<string> tmp = split(treeStr, '_');
    return TreeDeserializeByPre(tmp, 0);
    
}