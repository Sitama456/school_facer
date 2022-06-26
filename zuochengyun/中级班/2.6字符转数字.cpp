/**
 * @file 2.6字符转数字.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 将给定的数转为字符串, 1对应a 2对应b 给出可以转换的串的个数
 * 从左往右尝试, 从 i 位置往后的有效字符串是多少
 * 
 */

#include <string>
#include <vector>
using namespace std;

int translateMethods(string& s) {

}

int process(string& s, int i) {
    if (i == s.size()) {
        return 1;
    }
    if (s[i] == '0') {
        return 0;
    }

    if (s[i] == '1') {
        int res = process(s, i + 1);
        if (i + 1 < s.size()) {
            res += process(s, i + 2);
        }
        return res;
    }

    if (s[i] == '2') {
        int res = process(s, i + 1);
        if (i + 1 < s.size() && s[i + 1] >= '0' && s[i + 1] <= '6') {
            res += process(s, i + 2);
        }
        return res;
    }
    return process(s, i + 1);

    
}
