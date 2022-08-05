/**
 * @file 4.华为机试：k 对元素最小值.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 
 * 【编程题目 | 100分】k 对元素最小值 [ 100 / 中等 ]

k 对元素最小值
题目描述：
给定两个整数数组array1 array2，数组元素按升序排列假设从arr1 arr2中分别取出一个元素，可构成一对元素。
现在需要取出k对元素，并对取出的所有元素求和，计算和的最小值。
注意：两对元素对应arr1 arr2的下标是相同的视为同一对元素
输入描述:
输入两行数组arr1 arr2
每行首个数字为数组大小size 0<size<=100
arr1，2中的每个元素 0<arr[i]<1000
接下来一行 正整数k 0<k<=arr1.size * arr2.size
输出描述：
满足要求的最小值

示例 1：

输入
3 1 1 2
3 1 2 3
2
1
2
3
输出
4
1
说明
用例中需要取两个元素，
取第一个数组第0个元素与第二个数组第0个元素组成一个元素[1,1]
取第一个数组第1个元素与第二个数组第0个元素组成一个元素[1,1]
求和为1+1+1+1=4 ，满足要求最小
————————————————
版权声明：本文为CSDN博主「小朱小朱绝不服输」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/weixin_44052055/article/details/123969116
 */

/**
 * @brief 使用优先队列
 * 
 */
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

struct Pair {
    int index1 = -1;
    int index2 = -1;
    int num1 = 0;
    int num2 = 0;
    Pair(int i, int j, int n1, int n2) : index1(i), index2(j), num1(n1), num2(n2) {}
    int getSum() { return num1 + num2; }
};

struct cmp {
    bool operator()(Pair a, Pair b) {
        return a.getSum() > b.getSum();
    }
};

int minPairSum(vector<int>& nums1, vector<int>& nums2, int k) {
    //小根堆
    priority_queue<Pair, vector<Pair>, cmp> smallRootHeap;
    // 首先用 nums1[i] 和 nums[0]建立堆
    int size1 = nums1.size();
    for (int i = 0; i < min(k, size1); ++i) {
        smallRootHeap.push({i, 0, nums1[i], nums2[0]});
    }
    // 弹出堆顶元素
    int min = 0;
    while (k > 0 && !smallRootHeap.empty()) {
        // 取出堆顶元素
        // 此时堆顶一定是所有Pair中最小的 为什么? 因为第一次运行时包含了nums1[0] nums2[0]
        Pair pair = smallRootHeap.top();
        smallRootHeap.pop();
        min += pair.getSum();
        // 此时加入新元素 index1  index2 + 1
        // 因为此时 index1 index2 + 1 可能会是第二小的元素 这里可以画图
        int index1 = pair.index1;
        int index2 = pair.index2;
        if (index2 + 1 < nums2.size()) {
            smallRootHeap.push({index1, index2 + 1, nums1[index1], nums2[index2 + 1]});
        }
        k--;
    }
    return min;

}

vector<int> getVector(string& str) {
    char* tmp = strtok((char *)(str.data()), " ");
    vector<int> res;
    while (tmp != NULL) {
        res.push_back(atoi(tmp));
        tmp = strtok(NULL, " ");
    }
    return res;
}

int main(int argc, char* argv[]) {
    int k = 0;
    int n1 = 0;
    int n2 = 0;
    while (1) {
        cin >> n1;
        vector<int> nums1(n1);
        for (int i = 0; i < n1; ++i) {
            cin >> nums1[i];
        }
        cin >> n2;
        vector<int> nums2(n2);
        for (int i = 0; i < n2; ++i) {
            cin >> nums2[i];
        }
        cin >> k;
        cout << minPairSum(nums1, nums2, k) << endl;
    }
    return 0;
}