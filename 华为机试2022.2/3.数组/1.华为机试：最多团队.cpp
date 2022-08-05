/**
 * @file 1.华为机试：最多团队.cpp
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
 * 【编程题目 | 100分】最多团队 [ 100 / 中等 ]

最多团队
题目描述：
用数组代表每个人的能力，一个比赛活动要求参赛团队的最低能力值为N，每个团队可以由1人或2人组成，

且1个人只能参加1个团队， 请计算出最多可以派出多少支符合要求的团队？

输入描述:
5
3 1 5 7 9
8
第一行数组代表总人数，范围[1,500000]
第二行数组代表每个人的能力，每个元素的取值范围[1, 500000]，数组的大小范围[1,500000]
第三行数值为团队要求的最低能力值，范围[1, 500000]
输出描述：
3
最多可以派出的团队数量
示例 1：

输入
5
3 1 5 7 9
8
1
2
3
输出
3
1
说明
3,5组成一队，1,7组成一队，9自己一个队，故输出3

示例 2：

输入
7
3 1 5 7 9 2 6
8
1
2
3
输出
4
1
说明
1、7组成一队 3、5一队 2、6一队 9自己一队 输出4

示例 3：

输入
3
1 1 9
8
1
2
3
输出
1
1
说明
1、9组成一队 或者9自己一队 输出1
————————————————
版权声明：本文为CSDN博主「小朱小朱绝不服输」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/weixin_44052055/article/details/123957841
 */

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/**
 * @brief 找到数组中第一个>=key的位置
 * 
 * @param nums 
 * @param key 
 * @return int 
 */
int binarySearch(vector<int>& nums, int key) {
    int left = 0;
    int right = nums.size();
    int pos = right;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < key) {
            left = mid + 1;
        } else {
            pos = min(pos, mid);
            right = mid;
        }
    }
    return pos;
}


int maxTeamCount(vector<int>& abilities, int min) {
    int size = abilities.size();
    // 先排序 让能力值大于 min 的人自己一对
    sort(abilities.begin(), abilities.end());
    // 找到第一个能力值 >= min 的人
    int pos = binarySearch(abilities, min);
    int res = 0;
    res += size - pos;
    // 剩余的人一大一小搭配
    int left = 0;
    int right = pos - 1;
    while (left < right) {
        if (abilities[left] + abilities[right] >= min) {
            res++;
            right--;
            left++;
        } else {
            left++;
        }
    }
    return res;

}

int main(int argc, char* argv[]) {
    int n = 0;
    int min = 0;
    while (1) {
        cin >> n;
        vector<int> abilities(n);
        for (int i = 0; i < n; ++i) {
            cin >> abilities[i];
        }
        cin >> min;
        cout << maxTeamCount(abilities, min) << endl;

    }
    return 0;
}