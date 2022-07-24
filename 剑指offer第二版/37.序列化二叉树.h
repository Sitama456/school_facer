/**
 * @file 37.序列化二叉树.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 
 * 请实现两个函数，分别用来序列化和反序列化二叉树。

你需要设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。

提示：输入输出格式与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode 序列化二叉树的格式。你并非必须采取这种方式，你也可以采用其他的方法解决这个问题。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/xu-lie-hua-er-cha-shu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */


#include <vector>
#include <queue>
#include <string>
#include <stdio.h>
#include <string.h>
using namespace std;
#define NULL 0
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // 层序遍历序列化
        string res = "[";
        queue<TreeNode*> q;
        if (root == NULL) {
            res += "]";
            return res;
        }
        q.push(root);
        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            if (cur) {
                res += to_string(cur->val);
                res += ",";
                q.push(cur->left);
                q.push(cur->right);            
            } else {
                res += "#";
                res += ",";
            }
        }
        res.pop_back();
        res += "]";
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // 去掉首尾的[]
        int start = 1;
        int end = data.size() - 2;
        if (start > end) return NULL;
        vector<string> piece;
        SplitString(data.substr(start, end - start + 1), ",", piece);
        queue<TreeNode*> q;
        q.push(new TreeNode(atoi(piece[0].c_str())));
        TreeNode* root = q.front();
        int i = 1;
        int count = 1;
        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            if (piece[i] != "#") {
                cur->left = new TreeNode(atoi(piece[i].c_str()));
                q.push(cur->left);
            }
            i++;
            if (piece[i] != "#") {
                cur->right = new TreeNode(atoi(piece[i].c_str()));
                q.push(cur->right);
            }
            i++;
        }
        return root;
        

    }

    // 分割字符串
    void SplitString(string inputStr, char* sperChar, vector<string> &outVector)
    {
    	char *token = strtok((char*)inputStr.c_str(), sperChar);
        while (token != NULL) {
            outVector.push_back(token);
            token = strtok(NULL, sperChar);
        }
    }

};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));