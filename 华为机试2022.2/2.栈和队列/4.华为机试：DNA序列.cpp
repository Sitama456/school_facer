/**
 * @file 4.华为机试：DNA序列.cpp
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
 * DNA序列
描述
一个 DNA 序列由 A/C/G/T 四个字母的排列组合组成。 G 和 C 的比例（定义为 GC-Ratio ）是序列中 G 和 C 两个字母的总的出现次数除以总的字母数目（也就是序列长度）。在基因工程中，这个比例非常重要。因为高的 GC-Ratio 可能是基因的起始点。
给定一个很长的 DNA 序列，以及限定的子串长度 N ，请帮助研究人员在给出的 DNA 序列中从左往右找出 GC-Ratio 最高且长度为 N 的第一个子串。
DNA序列为 ACGT 的子串有: ACG , CG , CGT 等等，但是没有 AGT ， CT 等等

数据范围：字符串长度满足 1≤n≤1000，输入的字符串只包含 A/C/G/T 字母

输入描述：
输入一个string型基因序列，和int型子串的长度

输出描述：
找出GC比例最高的子串,如果有多个则输出第一个的子串

示例1：
输入
ACGT
2
1
2
输出
CG
1
说明
ACGT长度为2的子串有AC,CG,GT3个，其中AC和GT2个的GC-Ratio都为0.5，CG为1，故输出CG

示例2：
输入
AACTGTGCACGACCTGA
5
1
2
输出
GCACG
1
说明
虽然CGACC的GC-Ratio也是最高，但它是从左往右找到的GC-Ratio最高的第2个子串，所以只能输出GCACG。

思路分析：
题目中主要信息：

输入的字符串中只有ACGT四种字符
限定长度为nnn的子串，求其中CG比例最高的第一个子串
解读： 长度限定的情况下，要找比例越高即找出现次数越多
————————————————
版权声明：本文为CSDN博主「小朱小朱绝不服输」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/weixin_44052055/article/details/124121185
 */
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

string getTheSubStr(string& str, int len) {
    int size = str.size();
    int right = 0;
    int pos = -1;
    int count = 0;
    int maxCount = 0;
    while (right < size) {
        // 右侧进来一个数
        char c = str[right];
        if (c == 'G' || c == 'C') {
            count++;
        }
        // 左侧出去一个值
        if (right - len >= 0) {
            if (str[right - len] == 'C' || str[right - len] == 'G') {
                count--;
            }
        }
        // 形成了窗口
        if (right > len - 1) {
            if (maxCount < count) {
                maxCount = count;
                pos = right;
            }
        }
        ++right;
    }
    return str.substr(pos - len + 1, len);
    
}

int main(int argc, char* argv[]) {
    string inputStr;
    int len = 0;
    while (1) {
        cin >> inputStr;
        cin >> len;
        cout << getTheSubStr(inputStr, len) << endl;
    }
    return 0;
}