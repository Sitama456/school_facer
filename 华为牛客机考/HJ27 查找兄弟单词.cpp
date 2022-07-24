/**
 * @file HJ27 查找兄弟单词.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 
 * 描述
定义一个单词的“兄弟单词”为：交换该单词字母顺序（注：可以交换任意次），而不添加、删除、修改原有的字母就能生成的单词。
兄弟单词要求和原来的单词不同。例如： ab 和 ba 是兄弟单词。 ab 和 ab 则不是兄弟单词。
现在给定你 n 个单词，另外再给你一个单词 x ，让你寻找 x 的兄弟单词里，按字典序排列后的第 k 个单词是什么？
注意：字典中可能有重复单词。

数据范围：1 \le n \le 1000 \1≤n≤1000 ，输入的字符串长度满足 1 \le len(str) \le 10 \1≤len(str)≤10  ， 1 \le k < n \1≤k<n 
输入描述：
输入只有一行。 先输入字典中单词的个数n，再输入n个单词作为字典单词。 然后输入一个单词x 最后后输入一个整数k
输出描述：
第一行输出查找到x的兄弟单词的个数m 第二行输出查找到的按照字典顺序排序后的第k个兄弟单词，没有符合第k个的话则不用输出。
 */

#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;



bool isBrotherWord(string& str, string x, vector<int> cnt);

int main(){
    vector<string> strs;
    int k = 0;
    int N = 0;
    vector<string> res;
    cin >> N;
    strs.resize(N);
    string x;
    int i = 0;
    while (N--) {
        cin >> strs[i++]; 
    }
    cin >> x;
    cin >> k;
    vector<int> cnt(26, 0);
    for (char c : x) cnt[c - 'a']++;
    sort(strs.begin(), strs.end());
    for (string& s : strs) {
        if (isBrotherWord(s, x, cnt)) {
            res.push_back(s);
        }
    } 
    cout << res.size() << endl;
    if (k <= res.size()) {
        cout << res[k - 1];
    }
    
}

bool isBrotherWord(string& str, string x, vector<int> cnt) {
    if (str == x) return false;
    int len = x.size();
    for (char c : str) {
        if (cnt[c - 'a'] == 0) {
            return false;
        }
        cnt[c - 'a']--;
        len--;
    }
    return len == 0;
}

