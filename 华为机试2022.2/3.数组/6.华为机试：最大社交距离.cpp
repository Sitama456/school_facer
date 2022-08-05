/**
 * @file 6.华为机试：最大社交距离.cpp
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
 * 【编程题目 | 200分】最大社交距离 [ 200 / 中等 ]

最大社交距离
题目描述：
疫情期间需要大家保证一定的社交距离，公司组织开交流会议。

座位一排共 N 个座位，编号分别为 [0, N - 1] , 要求员工一个接着一个进入会议室，并且可以在任何时候离开会议室。

满足：

每当一个员工进入时，需要坐到最大社交距离（最大化自己和其他人的距离的座位）；
如果有多个这样的座位，则坐到 索引最小 的那个座位。
输入描述：
会议室座位总数 seatNum 。(1 <= seatNum <= 500)
员工的进出顺序 seatOrLeave 数组，元素值为 1，表示进场；元素值为负数，表示出场（特殊：位置 0 的员工不会离开）。
例如 - 4 表示坐在位置 4 的员工离开（保证有员工坐在该座位上）
输出描述：
最后进来员工，他会坐在第几个位置，如果位置已满，则输出 - 1 。

示例 1：
输入
10
[1,1,1,1,-4,1]
1
2
输出
5
1
说明
seat -> 0 , 空在任何位置都行，但是要给他安排索引最小的位置，也就是座位 0
seat -> 9 , 要和旁边的人距离最远，也就是座位 9
seat -> 4 , 要和旁边的人距离最远，应该坐到中间，也就是座位 4
seat -> 2 , 员工最后坐在 2 号座位上
leave [4] , 4 号座位的员工离开
seat -> 5 , 员工最后坐在 5 号座位上
————————————————
版权声明：本文为CSDN博主「小朱小朱绝不服输」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/weixin_44052055/article/details/124040054
 */


#include <vector>
#include <string.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

int theLastSeat(vector<int>& seats, int N) {
    set<int> in; // 有人坐着的座位
    
    int size = seats.size();
    int res = 0;
    for (int i = 0; i < size; ++i) {
        int op = seats[i];
        if (op > 0) { // 占座
            if (in.empty()) { // 第一个人
                in.insert(0); // 坐 0 号位子
                res = 0;
            } else if (in.size() == 1) {
                // 第二个人 坐最后一个位置上
                in.insert(N - 1);
                res = N - 1;
            } else if (in.size() > 1 && in.size() < N) { // 中间的人 并且没有坐满
                vector<int> sitedSeats(in.begin(), in.end());
                // 找最大的距离
                int maxDistance = 0;
                int start = 0;
                int i = 0;
                for (; i < sitedSeats.size() - 1; ++i) {
                    int distance = (sitedSeats[i + 1] - sitedSeats[i]) / 2;
                    if (distance > maxDistance) {
                        start = sitedSeats[i];
                        maxDistance = distance;
                    }
                }
                // 最后一个位置 比较特殊 因为其右边没有座位 所以不需要除以2
                if (N - 1 - sitedSeats[i] > maxDistance) {
                    start = sitedSeats[i];
                    maxDistance = N - 1 - sitedSeats[i];
                }
                // start + maxDistance就是要分配的位置
                in.insert(start + maxDistance);
                res = start + maxDistance;
            } else {
                // 没有座位了
                return - 1;
            }
        } else { // 离开
            if (in.find(-op) == in.end()) {
                cout << "no peopel in leaved seat!" << endl;
                return -1;
            }
            in.erase(-op);
        }
    }
    return res;
}

int main(int argc, char* argv[]) {
    int N = 0;
    string inputStr;
    while (1) {
        cin >> N;
        getchar(); // 读掉换行符
        getline(cin, inputStr);
        inputStr.pop_back();
        char* tmp = strtok((char *)(&inputStr[1]), ",");
        vector<int> seat;
        while (tmp != NULL) {
            seat.push_back(atoi(tmp));
            tmp = strtok(NULL, ",");
        }
        cout << theLastSeat(seat, N) << endl;
    }
    return 0;
}