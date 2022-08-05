/**
 * @file 009.书籍叠放.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief https://blog.csdn.net/weixin_37580235/article/details/125116126
 * 将长度排序之后，就是求宽度的最长递增子序列 但是要考虑到长度相等的情况
 */
#include <vector>
#include <algorithm>
using namespace std;

struct book {
    int len = 0;
    int width = 0;
    book(int l, int w) : len(l), width(w) {}
};


// struct cmp {
// public:
//     bool operator()(book a, book b) {
//         return a.len < b.len;
//     }
// };
bool cmp (book a, book b) {
    return a.len < b.len;
}

/**
 * @brief 求以i位置结尾的最长递增子序列长度
 * 
 * @param books 
 * @param i 
 * @return int 
 */
int maxUpOrderSubArrLen(vector<book>& books, int i) {
    if (i == 0) {
        return 1;
    }
    if (books[i].len > books[i - 1].len && books[i].width > books[i - 1].width) {
        return maxUpOrderSubArrLen(books, i - 1) + 1;
    }
    return 1;
}
/**
 * @brief 
 * 
 * @param books 
 * @return int 
 */
int maxBookNum(vector<book>& books) {
    // 排序
    sort(books.begin(), books.end(), cmp);
    int maxNum = 0;
    for (int i = 0; i < books.size(); ++i) {
        maxNum = max(maxNum, maxUpOrderSubArrLen(books, i));
    }
    return maxNum;
}

