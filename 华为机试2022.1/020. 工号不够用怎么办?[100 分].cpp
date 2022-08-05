/**
 * @file 020. 工号不够用怎么办?[100 分].cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief https://blog.csdn.net/weixin_37580235/article/details/125133609
 * 
 */

int minLenOfNum(int num, int charNum) {
    // 如果认识小于等于26 则为1 因为不能全为字母或者数字
    if (num <= 26) return 1;
    // 字母部分能表示的人数个数
    long limit = 1;
    for (int i = 0; i < charNum; ++i) {
        limit *= 26;
    }
    // 数字部分能表示的人数个数 先初始化为1
    int res = 1;
    limit *= 10;
    while (limit < num) {
        res++;
        limit *= 10;
    }
    return res;
}