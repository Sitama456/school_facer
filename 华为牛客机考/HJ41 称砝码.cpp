/**
 * @file HJ41 称砝码.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 
 * 描述
现有n种砝码，重量互不相等，分别为 m1,m2,m3…mn ；
每种砝码对应的数量为 x1,x2,x3...xn 。现在要用这些砝码去称物体的重量(放在同一侧)，问能称出多少种不同的重量。


注：

称重重量包括 0

数据范围：每组输入数据满足 1 \le n \le 10 \1≤n≤10  ， 1 \le m_i \le 2000 \1≤m 
i
​
 ≤2000  ， 1 \le x_i \le 10 \1≤x 
i
​
 ≤10 
输入描述：
对于每组测试数据：
第一行：n --- 砝码的种数(范围[1,10])
第二行：m1 m2 m3 ... mn --- 每种砝码的重量(范围[1,2000])
第三行：x1 x2 x3 .... xn --- 每种砝码对应的数量(范围[1,10])
输出描述：
利用给定的砝码可以称出的不同的重量数
 * 
 */

#include<iostream>
#include<vector>
#include <unordered_set>
using namespace std;

int weightMethodNum(vector<int>& weights, vector<int>& nums);
int main(){
    int kindNum = 0;
    cin >> kindNum;
    int tmp = kindNum;
    int tmp1 = 0;
    vector<int> weights;
    vector<int> nums;
    while (tmp--) {
        cin >> tmp1;
        weights.push_back(tmp1);
    }
    while (kindNum--) {
        cin >> tmp1;
        nums.push_back(tmp1);
    }
    unordered_set<int> s;
    s.insert(0);
    // 遍历每一种砝码
    for (int i = 0; i < weights.size(); ++i) {
        // 用 j 个数量
        for (int j = 1; j <= nums[i]; ++j) {
            unordered_set<int> temp(s); // 当前集合的元素都可以加一次
            for (auto it = temp.begin(); it != temp.end(); ++it) {
                s.insert(*it + weights[i]);
            }
        }
    }
    cout << s.size();
    return 0;
    
}


