/**
 * @file 1.华为机试：TLV解析Ⅰ.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 
 * TLV解析Ⅰ
题目描述：
TLV 编码是按 [ Tag Length Value ] 格式进行编码的，一段码流中的信元用Tag标识， Tag在码流中 唯一不重复 ，Length表示信元Value的长度，Value表示信元的值。
码流以某信元的Tag开头，Tag固定占 一个字节，Length固定占 两个字节，字节序为 小端序 。
现给定TLV格式编码的码流，以及需要解码的信元Tag，请输出该信元的Value。
输入码流的16进制字符中，不包括小写字母，且要求输出的16进制字符串中也不要包含小写字母；
码流字符串的最大长度不超过50000个字节。
输入描述：
输入的第一行为一个字符串，表示待解码信元的 Tag ；
输入的第二行为一个字符串，表示待解码的 16进制码流 ，字节之间用 空格分隔 。
输出描述:
输出一个字符串，表示待解码信元以16进制表示的 Value 。
示例 1 ：

输入
31
32 01 00 AE 90 02 00 01 02 30 03 00 AB 32 31 31 02 00 32 33 33 01 00 CC
1
2
输出
32 33
1
说明
需要解析的信元的Tag是31，从码流的起始处开始匹配，
Tag为32的信元长度为1（01 00，小端序表示为1）；
第二个信元的Tag是90，其长度为2；
第三个信元的Tag是30，其长度为3；
第四个信元的Tag是31，其长度为2（02 00），所以返回长度后面的两个字节即可，即32 33。
————————————————
版权声明：本文为CSDN博主「小朱小朱绝不服输」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/weixin_44052055/article/details/123903244
 * 
 */

#include <string>
#include <string.h>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

struct HexStr {
    string numStr;
    HexStr(string str) : numStr(str) {}
    HexStr(char* pstr) : numStr(pstr) {}
    int strToInt() {
        return atoi(numStr.c_str());
    }
};


vector<HexStr> TLV_decode(vector<HexStr>& hexStrs, int targetTag) {
    int i = 0;
    int len = hexStrs.size();
    vector<HexStr> res;
    while (i < len) {
        // 先取tag
        int tag = hexStrs[i].strToInt();
        // 取长度
        int length = hexStrs[i + 2].strToInt() * 16 + hexStrs[i + 1].strToInt();
        if (tag == targetTag) {
            i += 3;
            // 跳过长度
            for (int j = 0; j < length; ++j) {
                res.push_back(hexStrs[i++]);
            }
            return res;
        } else {
            i += length + 3;
        }
        
    }
    return {};
}

int main() {
    int targetTag;
    string inputStr;
    while (1) {
        cin >> targetTag;
        vector<HexStr> hexStrs;
        getchar(); // 读掉换行符
        getline(cin, inputStr);
        char *tmp = strtok((char*)(inputStr.data()), " ");
        while (tmp != NULL) {
            hexStrs.push_back(tmp);
            tmp = strtok(NULL, " ");
        }
        vector<HexStr> res = TLV_decode(hexStrs, targetTag);
        for (int i = 0; i < res.size() - 1; ++i) {
            cout << res[i].numStr << " ";
        }
        if (res.size() - 1 >= 0) {
            cout << res[res.size() - 1].numStr << endl;
        }
    }
    return 0;
}