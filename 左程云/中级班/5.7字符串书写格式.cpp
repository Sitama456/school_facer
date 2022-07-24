/**
 * @file 5.7字符串书写格式.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 
 * 给定一个字符串，如果该字符串符合人们日常书写一个整数的形式，返回int类型的这个数；
 * 如果不符合或者越界返回-1或者报错
 * 
 */

/**
 * @brief 比如 7合法 07不合法 -3 合法 -03不合法
 * 1) 除了数字字符之外，只允许出现-号
 * 2) 如果有-号，只会出现在开头，且只出现一次，且后面必须跟着数字字符，且不能是0
 * 3) 如果开头为0，后续必须没有数字
 * 
 */

#include <string>
#include <exception>
using namespace std;

bool isValid(string str) {
    // 开头不是-也不是数字
    if (str[0] != '-' && (str[0] < '0' || str[0] > '9')) {
        return false;
    }
    // 如果是-号，并且只有-号
    if (str[0] == '-' && (str.size() == 1 || str[1] == '0')) {
        return false;
    }
    // 如果以0开头
    if (str[0] == '0' && str.size() > 1) {
        return false;
    }

    // 开头合法 后续字符必须是 0 ~ 9之间
    for (int i = 1; i < str.size(); ++i) {
        if (str[i] < '0' || str[i] > '9') {
            return false;
        }
    }
    return true;
}

int strToInt(string str) {
    if (str.empty()) return 0;
    if (isValid(str) == false) {
        throw std::exception();
    }

    // 越界判断时 先将数字转为负数 因为负数的表达范围要大一个
    // 比如 -2147483648 如果数字部分用正数去接，就会发生越界
    bool neg = str[0] == '-' ? true : false;
    int minq = INT32_MIN / 10;
    int minr = INT32_MAX % 10;
    int res = 0;
    int cur = 0;
    // 有效数字开始
    for (int i = neg ? 1 : 0; i < str.size(); ++i) {
        // 以负数的形式接住这个数字
        cur = '0' - str[i];
        // 中途转换过程中溢出情况
        if ((res < minq) || (res == minq && cur < minr)) {
            throw new std::exception();
        }
        res = res * 10 + cur;
    }

    if (!neg && res == INT32_MIN) {
        throw std::exception();
    }
    return neg ? -res : res;
    
}