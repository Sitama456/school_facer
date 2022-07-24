#include <map>
#include <vector>
#include <string>
using namespace std;

class TrieNode {
public:
    int pass; // 这个节点到达过多少次
    int end; // 这个节点是多少个字符串的结尾节点
    vector<TrieNode*> nexts; // 走向下一个节点的路
    TrieNode() {
        pass = 0;
        end = 0;
        // nexts[index] 表示是否有走向 index + 'a' 的路
        nexts.resize(26);
    }
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    void insert(string word) {
        if (word.empty()) {
            return;
        }
        TrieNode* node = root;
        node->pass++;
        int index = 0;
        for (char c : word) {
            index = c - 'a';
            // 如果没有节点
            if (node->nexts[index] == nullptr) {
                node->nexts[index] = new TrieNode();
            }
            node = node->nexts[index];
            node->pass++;
        }
        node->end++;
    }

    int search(string word) {
        if (word.empty()) {
            return 0;
        }
        TrieNode* node = root;
        int index = 0;
        for (auto c : word) {
            index = c - 'a';
            if (node->nexts[index] == nullptr) {
                return 0;
            }
            node = node->nexts[index];
        }
        return node->end;
    }

    int prefixNumber(string pre) {
        if (pre.empty()) {
            return 0;
        }
        TrieNode* node = root;
        int index = 0;
        for (auto c : pre) {
            index = c - 'a';
            if (node->nexts[index] == nullptr) {
                return 0;
            }
            node = node->nexts[index];
        }
        return node->pass;
    }

    void deleteWord(string word) {
        if (search(word) == 0) {
            return;
        }
        TrieNode* node = root;
        node->pass--;
        int index = 0;
        for (auto c : word) {
            index = c - 'a';
            if (--node->nexts[index]->pass== 0) {
                // 释放指针
                deleteNodes(node->nexts[index]);
                return;
            }
            node = node->nexts[index];
        }
        node->end--;

    }

    void deleteNodes(TrieNode* start) {
        if (start == nullptr) {
            return;
        }
        for (TrieNode* node : start->nexts) {
            deleteNodes(node);
        }
        delete start;
        start = nullptr;
    }

};