/**
 * @file 剑指 Offer II 033. 变位词组.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 
 * 给定一个字符串数组 strs ，将 变位词 组合在一起。 可以按任意顺序返回结果列表。

注意：若两个字符串中每个字符出现的次数都相同，则称它们互为变位词。
 */
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> maps;
        for (string& s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            maps[key].push_back(s);
        }
        vector<vector<string>> res;
        for (auto it = maps.begin(); it != maps.end(); ++it) {
            res.push_back(it->second);
        }
        return res;
        
    }
};