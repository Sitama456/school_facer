/**
 * @file 12.华为机试：磁盘容量排序.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 
 * 【编程题目 | 100分】磁盘容量排序 [ 100 / 中等 ]
磁盘容量排序

题目描述：
磁盘的容量单位常用的有M，G，T这三个等级，它们之间的换算关系为1T = 1024G，1G = 1024M，
现在给定n块磁盘的容量，请对它们按从小到大的顺序进行稳定排序，
例如给定5块盘的容量，1T，20M，3G，10G6T，3M12G9M排序后的结果为20M，3G，3M12G9M，1T，10G6T。
注意单位可以重复出现，上述3M12G9M表示的容量即为3M+12G+9M，和12M12G相等。
输入描述：
输入第一行包含一个整数n(2 <= n <= 100)，表示磁盘的个数，
接下的n行，每行一个字符串(长度大于2，小于30)，表示磁盘的容量，
由一个或多个格式为mv的子串组成，其中m表示容量大小，v表示容量单位，
例如20M，1T，30G，10G6T，3M12G9M。
磁盘容量m的范围为1到1024的正整数，容量单位v的范围只包含题目中提到的M，G，T三种，换算关系如题目描述。

输出描述：
输出n行，表示n块磁盘容量排序后的结果。

示例 1：
输入
3
1G
2G
1024M
1
2
3
4
输出
1G
1024M
2G
1
2
3
说明
1G和1024M容量相等，稳定排序要求保留它们原来的相对位置，故1G在1024M之前

示例 2：
输入
3
2G4M
3M2G
1T
1
2
3
4
输出
3M2G
2G4M
1T
1
2
3
说明
1T的容量大于2G4M，2G4M的容量大于3M2G

思路分析
首先是对一个磁盘大小的计算，可以都换算成M，通过字符串分隔来计算磁盘大小。

然后是对磁盘的一个排序，还是使用二维数组，对于索引和大小进行排序，小的在前面，相等的索引在前面。还要找回对应的磁盘字符串，这里可以将索引和字符串存到一个哈希表里，方便查找。
————————————————
版权声明：本文为CSDN博主「小朱小朱绝不服输」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/weixin_44052055/article/details/124049468
 */

#include <vector>
#include <string.h>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

struct disk {
    string capacityStr;
    disk() {}
    disk(string s) : capacityStr(s) {}

    int getCountOfM(string cap) {
        int len = cap.size();
        int num = atoi(capacityStr.substr(0, len - 1).c_str());
        if (capacityStr[len - 1] == 'M') {
            return num;
        } else if (capacityStr[len - 1] == 'G') {
            return num * 1024;
        } else if (capacityStr[len - 1] == 'T') {
            return num * 1024 * 1024;
        } else {
            return 0;
        }
    }

    int getCountOfM() {
        int len = capacityStr.size();
        int i = 0;
        int j = i;
        int res = 0;
        while (i < len) {
            // 跳过数字
            while (i < len && isdigit(capacityStr[i])) {
                i++;
            }
            res += getCountOfM(capacityStr.substr(j, i - j + 1));
            // 跳过字母
            while (i < len && !isdigit(capacityStr[i])) {
                i++;
            }
            j = i;
        }    
        return res;
    }
};

bool cmp(disk a, disk b) {
    return a.getCountOfM() < b.getCountOfM();
}

void sort(vector<disk>& disks) {
    sort(disks.begin(), disks.end(), cmp);
}

int main(int argc, char* argv[]) {
    int n;
    string inputStr;
    while (1) {
        cin >> n;
        vector<disk> disks(n);
        for (int i = 0; i < n; ++i) {
            cin >> inputStr;
            disks[i].capacityStr = inputStr;
        }
        sort(disks);
        for (int i = 0; i < n; ++i) {
            cout << disks[i].capacityStr << endl;
        }
    }
    return 0;
}