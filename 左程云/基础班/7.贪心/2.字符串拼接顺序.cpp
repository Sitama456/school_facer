/**
 * @file 2.字符串拼接顺序.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 给定一个字符串数组，将其中所有字符串拼接起来，如何拼接使得结果字典序最小
 * 字典序： 如果两个字符串长度一样，则认为两个字符串为26进制的数比较。
 *         如果长度不一样，则将短的补0，和长的字符串一样长
 * 贪心1：按字典序排序，谁小谁在前面。不对。反例 "b" "ba" -> "bba"。其实 "bab" 更小
 * 贪心2：两字符串 a b。 如果 a b < b a, 则 a 排在前面
 */

#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

/**
 * @brief 贪心策略
 * 1. 根据某标准建立一个比较器来排序
 * 2. 根据某标准建立一个比较器来组成堆 
 * 
 */




/**
 * @brief 字符串转换字典序函数
 * 
 * @param str 转换的字符串
 * @param len 转换长度 不足则补0
 * @return int 
 */
int stringToInt(string str, int len) {
    int size = str.size();
    int count = len - size; 
    int result = 0;
    for (int i = size - 1; i >= 0; --i) {
        result += (str[i] - 'a') * pow(26, count);
        count++;
    }
    return result;
}

string lowestString(vector<string>& strs) {
    bool cmp = [](string str1, string str2)->bool{
        string tmp1 = str1 + str2;
        string tmp2 = str2 + str1;
        int len = str1.size() + str2.size();
        int num1 = stringToInt(tmp1, len);
        int num2 = stringToInt(tmp2, len);
        return num1 < num2;
             
    };
    sort(strs.begin(), strs.end(), cmp);
    string result;
    for (auto& str : strs) {
        result += str;
    }
    return result;
    
}