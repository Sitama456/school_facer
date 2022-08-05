/**
 * @file 034. 数组二叉树[200 分].cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief https://blog.csdn.net/weixin_37580235/article/details/125175506
 * 
 */

#include <vector>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;


vector<int> minNodePath(vector<int>& nums, int i) {
    vector<int> path;
    path.push_back(nums[i]);
    int left = 2 * i;
    int right = 2 * i + 1;
    vector<int> leftPath;
    vector<int> rightPath;
    if (left < nums.size() && nums[left] != -1) {
        leftPath = minNodePath(nums, left);
    } 
    if (right < nums.size() && nums[right] != -1) {
        rightPath = minNodePath(nums, right);
    }
    // 看哪个叶子节点更小
    vector<int>* min;
    if (leftPath.empty()) {
        min = &rightPath;
    } else if (rightPath.empty()) {
        min = &leftPath;
    } else if (leftPath.back() < rightPath.back()) {
        min = &leftPath;
    } else {
        min = &rightPath;
    }
    for (int num : *min) {
        path.push_back(num);
    }
    return path;
}

int main() {
    string inputStr;
    while (1) {
        getline(cin, inputStr);
        char* tmp = strtok((char*)(inputStr.data()), " ");
        vector<int> nums;
        nums.push_back(-1);
        while (tmp != NULL) {
            nums.push_back(atoi(tmp));
            tmp = strtok(NULL, " ");
        }
        vector<int> path = minNodePath(nums, 1);
        for (int num : path) {
            cout << num << " ";
        }
        cout << endl;
    }
}







