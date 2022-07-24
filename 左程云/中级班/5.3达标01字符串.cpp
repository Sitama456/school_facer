/**
 * @file 5.2达标01字符串.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 字符串只有 '0' 和 '1'两种字符构成。
 * 如果某一个字符串中，只要是出现'0'的位置，左边就靠着'1',这样的字符串叫做达标字符串
 * 1) 打表法暴力 发现是斐波那契数列问题 
 * 2) 递归函数定义为 F(i), 长度为i的字符串在前一个字符为1的情况下，长度为i
 *      的字符串的自由选择的情况。加入 N = 8, 则只能调F(7);因为第一个字符
 *      只能是1
 */

int F(int i) {
    if (i == 1) {
        return 1;
    }
    if (i == 2) {
        return 2;
    }
    // i 位置填 0, 则下一个字符必须填1
    int res0 = F(i - 2);
    // i 位置填1
    int res1 = F(i - 1);
    return res0 + res1;
} 