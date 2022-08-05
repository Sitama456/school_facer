/**
 * @file 2.华为机试：VLAN资源池.cpp
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
 * VLAN资源池
题目描述：
VLAN是一种对局域网设备进行逻辑划分的技术，为了标识不同的VLAN，引入VLAN ID(1-4094之间的整数)的概念。

定义一个VLAN ID的资源池(下称VLAN资源池)，资源池中连续的VLAN用开始VLAN-结束VLAN表示，不连续的用单个整数表示，所有的VLAN用英文逗号连接起来。

现在有一个VLAN资源池，业务需要从资源池中申请一个VLAN，需要你输出从VLAN资源池中移除申请的VLAN后的资源池。

输入描述:
第一行为字符串格式的VLAN资源池，第二行为业务要申请的VLAN，VLAN的取值范围为[1,4094]之间的整数。

输出描述:
从输入VLAN资源池中移除申请的VLAN后字符串格式的VLAN资源池，输出要求满足题目描述中的格式，并且按照VLAN从小到大升序输出。

如果申请的VLAN不在原VLAN资源池内，输出原VLAN资源池升序排序后的字符串即可。

示例 1：

输入
1-5
2
1
2
输出
1,3-5
1
说明
原VLAN资源池中有VLAN 1、2、3、4、5，从资源池中移除2后，剩下VLAN 1、3、4、5，按照题目描述格式并升序后的结果为1,3-5。

示例 2：

输入
20-21,15,18,30,5-10
15
1
2
输出
5-10,18,20-21,30
1
说明
原VLAN资源池中有VLAN 5、6、7、8、9、10、15、18、20、21、30，从资源池中移除15后，资源池中剩下的VLAN为 5、6、7、8、9、10、18、20、21、30，按照题目描述格式并升序后的结果为5-10,18,20-21,30。

示例 3：

输入
5,1-3
10
1
2
输出
1-3,5
1
说明
原VLAN资源池中有VLAN 1、2、3，5，申请的VLAN 10不在原资源池中，将原资源池按照题目描述格式并按升序排序后输出的结果为1-3,5。

备注：
输入VLAN资源池中VLAN的数量取值范围为[2-4094]间的整数，资源池中VLAN不重复且合法([1,4094]之间的整数)，输入是乱序的。
————————————————
版权声明：本文为CSDN博主「小朱小朱绝不服输」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/weixin_44052055/article/details/123908679
 * 
 */

#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct range {
    int start = 0;
    int end = 0;
    range(int s, int e) : start(s), end(e) { }
};
bool cmp(range a, range b) {
    return a.start < b.start;
}
vector<range> restVLANPool(string& s, int requestID) {
    char *tmp = strtok((char*)(s.data()), ",");
    vector<range> res;
    string tmps;
    int start = 0;
    int end = 0;
    while (tmp != NULL) {
        tmps = tmp;
        int spilitPos = tmps.find('-');
        if (spilitPos != -1) {
            start = atoi(tmps.substr(0, spilitPos).c_str());
            end = atoi(tmps.substr(spilitPos + 1).c_str());
        } else {
            start = end = atoi(tmp);
        }
        if (start <= requestID && requestID <= end) {
            int start1 = start;
            int end1 = requestID - 1;
            int start2 = requestID + 1;
            int end2 = end;
            if (start1 <= end1) res.push_back({start1, end1});
            if (start2 <= end2) res.push_back({start2, end2});
        } else {
            res.push_back({start, end});
        }
        tmp = strtok(NULL, ",");
    }
    sort(res.begin(), res.end(), cmp);
    return res;
}

string getRangeStr(range& range) {
    string tmp;
    if (range.start == range.end) {
        return to_string(range.start);
    } else {
        tmp += to_string(range.start);
        tmp += "-";
        tmp += to_string(range.end);
        return tmp;
    }

}

int main(int argc, char* argv[]) {
    string inputStr;
    int id;
    while (1) {
        cin >> inputStr;
        cin >> id;
        vector<range> res = restVLANPool(inputStr, id);
        int size = res.size();
        for (int i = 0; i < size - 1; ++i) {
            cout << getRangeStr(res[i]) << ",";
        }
        if (size - 1 >= 0) {
            cout << getRangeStr(res[size - 1]) << endl;
        }
    }
    return 0;
}