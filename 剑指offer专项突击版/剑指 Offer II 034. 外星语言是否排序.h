/**
 * @file 剑指 Offer II 034. 外星语言是否排序.h
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
 * 
 */
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        if (words.size() <= 1) return true;
        //字典序
        vector<int> charOrder(26, 0);
        for (int i = 0; i < order.size(); ++i) {
            charOrder[order[i] - 'a'] = i;
        }

        for (int i = 0; i < words.size() - 1; ++i) {
            if (!compare(words[i], words[i + 1], charOrder)) {
                return false;
            }
        }
        return true;
    }
    // b > a : true
    bool compare(string& a, string& b, vector<int>& charOrder) {
        int i = 0;
        int j = 0;
        while (i < a.size() && j < b.size()) {
            char c1 = a[i];
            char c2 = b[j];
            if (c1 == c2) {
                
            } else if (charOrder[c1 - 'a'] > charOrder[c2 - 'a']) { // a 在后头
                return false;
            } else {
                return true;
            }
            i++;
            j++;
        }
        return i == a.size() ? true : false;
    }

};