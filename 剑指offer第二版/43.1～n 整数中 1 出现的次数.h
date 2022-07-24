/**
 * @file 43.1～n 整数中 1 出现的次数.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 
 * 输入一个整数 n ，求1～n这n个整数的十进制表示中1出现的次数。

例如，输入12，1～12这些整数中包含1 的数字有1、10、11和12，1一共出现了5次。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/1nzheng-shu-zhong-1chu-xian-de-ci-shu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

class Solution {
public:
    int countDigitOne(int n) {
        // 计算每一位上出现的1的个数
        // cur 前面为高位 high, 后面为低位 low
        // 当cur 来到某位时，如果cur = 0; 例如
        // 2304 则十进制上的1的个数为 0010 ~ 2219 有多少个十进制的1呢？ 0010 0011 0012 ... 2210 2212 2213...
        // 只看高低位 000 ~ 229的变化 即 229 - 0 + 1 = 230个。也就是 high * 10
        // 如果 cur = 1 例如
        // 2415 则十进制上的1的个数为 0010 ~ 2415 : 0010 0011 0012 ... 2410 2411 2412... 2415
        // 只看高低为 000 ~ 245的变化 即 245 - 0 + 1 = 246。也就是 high * 10 + low + 1
        // 如果cur > 1 例如
        // 2568 则十进制上1的个数为 0010 ~ 2519 : 0010 0011 0012 ... 2510 2511..2519
        // 只看高低位 000 ~ 259 的变化 即 259 - 0 + 1 = 260。也加上(high + 1) * 10;

        // 如果cur 来到 百位 例如
        // 2304 ： 0100 ~ 2199   0100 0101 0102 ... 2198 2199
        // 即 (2 + 1) * 100 = 300 个
        int res = 0;
        int high = n / 10;
        int low = 0;
        long digit = 1; // 要用long digit在最后一位时可能会溢出
        int cur = n % 10;
        while (high != 0 || cur != 0) {
            if (cur == 0) res += high * digit;
            else if (cur == 1) res += high * digit + low + 1;
            else res += (high + 1) * digit;
            low += cur * digit;
            cur = high % 10;
            high /= 10;
            digit *= 10;

        }
        return res;
    }
};