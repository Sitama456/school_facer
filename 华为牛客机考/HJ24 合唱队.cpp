/**
 * @file HJ24 合唱队.cpp
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
N 位同学站成一排，音乐老师要请最少的同学出列，使得剩下的 K 位同学排成合唱队形。

设KK位同学从左到右依次编号为 1，2…，K ，他们的身高分别为T_1,T_2,…,T_KT 
1
​
 ,T 
2
​
 ,…,T 
K
​
  ，若存在i(1\leq i\leq K)i(1≤i≤K) 使得T_1<T_2<......<T_{i-1}<T_iT 
1
​
 <T 
2
​
 <......<T 
i−1
​
 <T 
i
​
  且 T_i>T_{i+1}>......>T_KT 
i
​
 >T 
i+1
​
 >......>T 
K
​
 ，则称这KK名同学排成了合唱队形。
通俗来说，能找到一个同学，他的两边的同学身高都依次严格降低的队形就是合唱队形。
例子：
123 124 125 123 121 是一个合唱队形
123 123 124 122不是合唱队形，因为前两名同学身高相等，不符合要求
123 122 121 122不是合唱队形，因为找不到一个同学，他的两侧同学身高递减。

你的任务是，已知所有N位同学的身高，计算最少需要几位同学出列，可以使得剩下的同学排成合唱队形。

注意：不允许改变队列元素的先后顺序 且 不要求最高同学左右人数必须相等

数据范围： 1 \le n \le 3000 \1≤n≤3000 
 * 
 */

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

/**
* 转换为求可移除元素的 最长递增序列个数 和 最长递减序列个数
*
*/

int removeMinPeople(vector<int>& peoples);
int main(){
    int N = 0;
    cin >> N;
    vector<int> peoples(N, 0);
    int i = 0;
    while (N--) {
        cin >> peoples[i++]; 
    }
    cout << removeMinPeople(peoples);
    return 0;
}

int removeMinPeople(vector<int>& peoples) {
    int size = peoples.size();
    if (size <= 1) return 0;
    vector<int> up_dp(size, 1);
    vector<int> down_dp(size, 1);
    
    for (int i = 0; i < size; ++i) {
        // 因为是可以移除元素的最长递增序列 所以需要遍历 0 ~ i - 1
        for (int j = 0; j < i; ++j) {
            if (peoples[i] > peoples[j])
                up_dp[i] = max(up_dp[i], up_dp[j] + 1);
        }
    }
    
    for (int i = size - 1; i >= 0; --i) {
        for (int j = size - 1; j > i; --j) {
            if (peoples[i] > peoples[j]) {
                down_dp[i] = max(down_dp[i], down_dp[j] + 1);
            }
        }
    }
    int maxLen = 0; 
    for (int i = 0; i < size; ++i) {
        maxLen = max(maxLen, up_dp[i] + down_dp[i] - 1); 
    }
    return size - maxLen;
}