/**
 * @file 44.数字序列中某一位的数字.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 数字以0123456789101112131415…的格式序列化到一个字符序列中。在这个序列中，第5位（从下标0开始计数）是5，第13位是1，第19位是4，等等。

请写一个函数，求任意第n位对应的数字。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/shu-zi-xu-lie-zhong-mou-yi-wei-de-shu-zi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */

class Solution {
public:
    int findNthDigit(int n) {
        if (n == 0) {
            return 0;
        }
        // 1 确定在哪一个级别
        int start = 1;  // 从哪开始  1 10 100
        int digit = 1;  // 每个数有几个位
        long count = 9; // 每个级别共有几个位
        while (n > count) {
            n =(int)(n - count);
            start *= 10;
            digit++;
            count = (long)9 * start * digit;
        }
        // 确定该位在该数的第几个数字 在加上起始的数字
        // start 是从 1， 10， 100...开始的 也就是当前级别的第 1 位 数位是从0开始的第 n 位
        // 0 1 ...   9 10 ...  99 100
        // 比如11位，start = 10  digit = 2  n = 2  num = (2 - 1) / 2 + 10 = 10
        // 而不是 num = 2 / 2 + 10 = 11
        int num = start + (n - 1) / digit;

        // 确定该位在该数字的第几位
        int ret = to_string(num)[(n - 1) % digit] - '0';
        return ret;

        
    }
};