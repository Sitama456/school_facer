/**
 * @file 3.华为机试：停车场车辆统计.cpp
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
 * 【编程题目 | 100分】停车场车辆统计 [ 100 / 简单 ]
停车场车辆统计
题目描述：
特定大小的停车场，数组cars[]表示，其中1表示有车，0表示没车。
车辆大小不一，小车占一个车位（长度1），货车占两个车位（长度2），卡车占三个车位（长度3）。
统计停车场最少可以停多少辆车，返回具体的数目。
输入描述:
整型字符串数组cars[]，其中1表示有车，0表示没车，数组长度小于1000。

输出描述：
整型数字字符串，表示最少停车数目。

示例 1：

输入
1,0,1
1
输出
2
1
说明
1个小车占第1个车位
第二个车位空
1个小车占第3个车位
最少有两辆车
示例 2：

输入
1,1,0,0,1,1,1,0,1
1
输出
3
1
说明
1个货车占第1、2个车位
第3、4个车位空
1个卡车占第5、6、7个车位
第8个车位空
1个小车占第9个车位
最少3辆车
————————————————
版权声明：本文为CSDN博主「小朱小朱绝不服输」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/weixin_44052055/article/details/123960335
 */

#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/**
 * @brief 0 ~ i - 1不管 i ~ size 的最少停车
 * 
 * @param nums 
 * @param i 
 * @return int 
 */
int minCarCount(vector<int>& nums, int i) {
    if (i == nums.size()) return 0;
    int res = 0;
    if (nums[i] == 0) {
        res = minCarCount(nums, i + 1);
    } else {
        res = 1 + minCarCount(nums, i + 1);
        // 停的货车
        if (i + 1 < nums.size() && nums[i + 1] == 1) {
            res = min(res, 1 + minCarCount(nums, i + 2));
            // 停的卡车
            if (i + 2 < nums.size() && nums[i + 2] == 1) {
                res = min(res, 1 + minCarCount(nums, i + 3));
            }
        }
        
        
    }
    return res;
}

int main(int argc, char* argv[]) {
    string inputStr;
    while (1) {
        cin >> inputStr;
        char* tmp = strtok((char*)(inputStr.data()), ",");
        vector<int> nums;
        while (tmp != NULL) {
            nums.push_back(atoi(tmp));
            tmp = strtok(NULL, ",");
        }
        cout << minCarCount(nums, 0) << endl;
    }
    return 0;
}