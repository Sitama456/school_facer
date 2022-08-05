/**
 * @file 2.薪酬调整.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <string>
#include <string.h>
#include <iostream>
#include <stack>
#include <vector>
#include "../辅助工具/1.随机数组生成.h"


using namespace std;

int operationCount(vector<int>& nums) {
    int res = 0;
    stack<int> st;
    // 单调栈结构
    int size = nums.size();
    for (int i = 0; i < size; ++i) {
        while (!st.empty() && nums[i] > nums[st.top()]) {
            st.pop();
        }
        // 如果小于两倍
        while (!st.empty() && nums[i] < 2 * nums[st.top()]) {
            st.pop();
            res++;
        }
        st.push(i);
    }
    return res;
    
}




int getOperations(vector<int>& nums) {
    int size = nums.size();
    int res = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (nums[i] > 2 * nums[j]) {
                res++;
            }
        }
    }
    return res;
}






int mergeCount(vector<int>& nums, int start, int mid, int end) {
    vector<int> tmp(end - start + 1, 0);
    int L1 = start;
    int R1 = mid + 1;
    int res = 0;
    int count = 0;
    while (L1 <= mid && R1 <= end) {
        // 谁小就填谁
        if (nums[L1] < nums[R1]) {
            tmp[count++] = nums[L1++];
        } else {
            int tmpI = L1;
            while (tmpI <= mid &&nums[tmpI] <= 2 * nums[R1]) {
                tmpI++;
            }
            res += mid - tmpI + 1;
            tmp[count++] = nums[R1++];
        }
    }
    while (L1 <= mid) {
        tmp[count++] = nums[L1++];
    }
    while (R1 <= end) {
        tmp[count++] = nums[R1++];
    }
    for (int i = 0; i < count; ++i) {
        nums[i + start] = tmp[i];
    }
    return res;
}

int travelsal(vector<int>& nums, int start, int end) {
    if (start >= end) return 0;
    int mid = start + (end - start) / 2;
    int leftCount = travelsal(nums, start, mid);
    int rightCount = travelsal(nums, mid + 1, end);
    return leftCount + rightCount + mergeCount(nums, start, mid, end);
}
int main(int argc, char* argv[]) {
    // string inputStr;
    // while (1) {
    //     cin >> inputStr;
    //     inputStr.pop_back();
    //     char* tmp = strtok((char*)(&inputStr[1]), ",");
    //     vector<int> nums;
    //     while (tmp != NULL) {
    //         nums.push_back(atoi(tmp));
    //         tmp = strtok(NULL, ",");

    //     }
    //     cout << travelsal(nums, 0, nums.size() - 1) << endl;
    // }
    int time = 100000;
    int N = 200;
    for (int i = 0; i < time; ++i) {
        vector<int> A = randomArrayGenerator(N, 1, 10);
        vector<int> B = A;
        int num1 = getOperations(A);
        int num2 = travelsal(B, 0, B.size() - 1);
        if (num1 != num2) {
            for (int j = 0; j < A.size(); ++j) {
                cout << A[j] << " ";
            }
            cout << endl;
            cout << "ref : "  << num1 << " real : " << num2 << endl;

        }
        
    }
    
    cout << "OK" << endl;
}

