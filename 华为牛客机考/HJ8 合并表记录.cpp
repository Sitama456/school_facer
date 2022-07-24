/**
 * @file HJ8 合并表记录.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 
 * 描述
数据表记录包含表索引index和数值value（int范围的正整数），请对表索引相同的记录进行合并，即将相同索引的数值进行求和运算，输出按照index值升序进行输出。


提示:
0 <= index <= 11111111
1 <= value <= 100000

输入描述：
先输入键值对的个数n（1 <= n <= 500）
接下来n行每行输入成对的index和value值，以空格隔开

输出描述：
输出合并后的键值对（多行）
 */

#include<iostream>
#include<map>
using namespace std;

int main(){
    int n = 0;
    cin >> n;
    int key = -1;
    int value = 0;
    map<int, int> cnt;
    while (n--) {
        cin >> key;
        cin >> value;
        cnt[key] += value;
    }
    for (auto& pair : cnt) {
        cout << pair.first;
        cout << " ";
        cout << pair.second;
        cout << endl;
    }
    return 0;
}