/**
 * @file 004.火星文计算.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief https://blog.csdn.net/weixin_37580235/article/details/125112610
 * 先计算 $ 再计算 #
 */
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;



vector<int> OpStrToNum(string& opStr) {
    // 先将opStr转化成数字
    int len = opStr.size();
    int i = 0;
    while (i < len && !isdigit(opStr[i])) {
        i++;
    }
    int j = i;
    vector<int> opNum;
    while (i < len) {
        // 跳过数字段
        while (i < len && isdigit(opStr[i])) {
            i++;
        }
        int num = atoi(opStr.substr(j, i - j).c_str());
        // 保留操作符
        opNum.push_back(num);
        opNum.push_back(opStr[i]);
        // 跳过非字符字段
        while (i < len && !isdigit(opStr[i])) {
            i++;
        }
        j = i;
    }

}

int specialOpRes(vector<int>& opNum) {
    vector<int> res;
    int x = 0;
    int y = 0;
    // 先计算 $
    for (int i = 0; i < opNum.size(); ++i) {
        if (opNum[i] == '$') {
            x = res.back();
            res.pop_back();
            y = opNum[++i];
            res.push_back(3 * x + y + 2);
        } else {
            res.push_back(opNum[i]);
        }
    }
    vector<int> st;
    // 再计算 #
    for (int i = 0; i < res.size(); ++i) {
        if (res[i] == '$') {
            x = st.back();
            st.pop_back();
            y = res[++i];
            st.push_back(3 * x + y + 2);
        } else {
            st.push_back(res[i]);
        }
    }
    return st.back();
}