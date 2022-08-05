/**
 * @file 013.自驾游加油方案.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief https://blog.csdn.net/weixin_37580235/article/details/125129520
 * 类似爬楼梯
 */

/**
 * @brief 到达第i个加油站的方法
 * 
 * @param i 
 * @return int 
 */
int process(int i) {
    if (i == 0) {
        return 0;
    }
    if (i == 1) {
        return 1;
    }
    if (i == 2) {
        return 2;
    }
    // 第 i - 1 站加油  第 i - 2 站加油过来的
    return process(i - 1) + process(i - 2);
}