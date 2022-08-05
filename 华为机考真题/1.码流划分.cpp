/**
 * @file 1.码流划分.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <string>
#include <iostream>
#include <vector>

using namespace std;

// 获得数值
int getInt(string& str, int start, int end) {
    int size = end - start + 1;
    int count = 0;
    int res = 0;
    for (int i = end; i >= start; --i) {
        res += (str[i] - '0') * (1 << count++);
    }
    return res;
}
/**
 * @brief 从第 i 个位置开始 划分target
 * 

 */
bool backtrack(string& str, int i, vector<int>& path, vector<vector<int>>& res, int target) {
    if (path.size() == 3) {
        if (i == str.size()) {
            res.push_back(path);
            return true;
        }
        return false;       
    }
    int size = str.size();
    bool flag = false;
    // 逐个尝试
    for (int j = i; j < size; ++j) {
        if (getInt(str, i, j) == target) {
            path.push_back(j);
            flag = backtrack(str, j + 1, path, res, target);
            path.pop_back();
            if (flag) return flag;
        }

    }
    return false;
}

vector<int> spilitCodeStream(string& codeStream) {
    int size = codeStream.size();
    vector<int> path;
    vector<vector<int>> res;
    for (int i = 0; i < size; ++i) {
        path.push_back(i);
        int target = getInt(codeStream, 0, i);
        if (backtrack(codeStream, i + 1, path, res, target)) return res[0];
        path.pop_back(); 
    }
    return {};
}

int main(int argc, char* argv[]) {
    string inputStr;
    while (1) {
        cin >> inputStr;
        vector<int> res = spilitCodeStream(inputStr);
        if (res.empty()) cout << -1 << endl;
        int pre = 0;
        for (int i = 0; i < res.size(); ++i) {
            cout << inputStr.substr(pre, res[i] - pre + 1) << " ";
            pre = res[i] + 1;
        }
        cout << endl;
    }


}