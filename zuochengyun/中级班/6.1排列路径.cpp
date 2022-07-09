/**
 * @file 6.1排列路径.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 给定一个字符串类型数组，代表路径
 * str = ["b\\cst", "d\\", "a\\d\\e", "a\\b\\c"];
 * 请把这些路径中蕴含的结构画出来，子目录直接列在父目录的下面，并比父目录向右进两个
 * a
 *   b
 *     c
 *   d
 *     e
 * b
 *   cst
 * d
 * 同一级的需要按照字母顺序排列，不能乱
 * 
 * 建出一颗前缀树，再深度优先遍历即可
 * 
 */
#include <string>
#include <string.h>
#include <map>
#include <vector>
#include <sstream>
#include <memory>
#include <iostream>
using namespace std;
struct Node {
    string name;
    map<string, shared_ptr<Node>> edges;
    Node(string name) {
        this->name = name;
    } 
};


// 切割函数
void splitStrings(string src, const char split, vector<string>& strs) {
    istringstream iss(src);
    string token; // 接收缓冲区
    strs.clear();
    while (getline(iss, token, split)) {
        strs.push_back(token);
    }
}
Node* generatePrefixTree(vector<string> folders) {
    Node* head = new Node("");
    vector<string> strs;
    for (string& foldPath : folders) {
        splitStrings(foldPath, '\\', strs);
        Node* cur = head;
        for (int i = 0; i < strs.size(); ++i) {
            if (cur->edges.find(strs[i]) == cur->edges.end()) {
                cur->edges[strs[i]].reset(new Node(strs[i]));
                cur->edges[strs[i]]->name = strs[i];
            }
            cur = cur->edges[strs[i]].get();
        }
    }
    return head;
}

string get2nSpace(int levle) {
    string res;
    res.assign(2 * levle, ' ');
    return res;
}

void process(Node* head, int level) {
    if (level != 0) {
        cout << get2nSpace(level) + head->name << endl;
    }
    for (auto& node : head->edges) {
        process(node.second.get(), level + 1);
    }
}

void printPaths(vector<string>& folders) {
    if (folders.empty()) return;
    shared_ptr<Node> head(generatePrefixTree(folders));
    // 深度优先遍历
    process(head.get(), 0);
}