/**
 * @file 38.字符串的排列.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 输入一个字符串，打印出该字符串中字符的所有排列。

你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。
 * 
 */
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;
class Solution {
public:
    vector<string> permutation(string s) {
        vector<string> res;
        string path;
        vector<bool> used(s.size(), false);
        sort(s.begin(), s.end());
        // process(s, 0, path, res, used);
        process1(s, 0, path, res, used);
        return res;
    }

    void process(string& s, int i, string& path, vector<string>& res, vector<bool>& used) {
        if (i == s.size()) {
            res.push_back(path);
            return;
        }
        // 用于去重
        set<char> Set;
        for (int j = 0; j < s.size(); ++j) {
            if (used[j] || Set.find(s[j]) != Set.end()) {
                continue;
            }
            Set.insert(s[j]);
            used[j] = true;
            path.push_back(s[j]);
            process(s, i + 1, path, res, used);
            path.pop_back();
            used[j] = false;
        }
    }
    // s 已经排序好了
    void process1(string& s, int i, string& path, vector<string>& res, vector<bool>& used) {
        if (i == s.size()) {
            res.push_back(path);
            return;
        }
        for (int j = 0; j < s.size(); ++j) {
            if (used[j]) {
                continue;
            }
            // 树层去重 说明在这一层中 已将前一个已经用过了
            if (j > 0 && s[j] == s[j - 1] && !used[j - 1]) {
                continue;
            }
            used[j] = true;
            path.push_back(s[j]);
            process(s, i + 1, path, res, used);
            path.pop_back();
            used[j] = false;
        }
        
    }
};