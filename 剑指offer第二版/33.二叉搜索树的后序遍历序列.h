/**
 * @file 33.二叉搜索树的后序遍历序列.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同。
 * 
 */
#include <vector>
using namespace std;
class Solution {
public:
    // 左 右 中
    // 二叉搜索时 左 < 中 < 右
    bool verifyPostorder(vector<int>& postorder) {
        return process(postorder, 0, postorder.size() - 1);
    }

    // 递归方式
    bool process(vector<int>& postorder, int left, int right) {
        if (left >= right) {
            return true;
        }
        // 最后一个肯定是根节点
        int rootVal = postorder[right];
        // 找到左右子树的分割点
        int mid = left;
        while (postorder[mid] < rootVal) {
            mid++;
        }
        int tmp = mid;
        // 还要确定 tmp 后面的值都要比rootVal大 因为是右子树
        while (tmp < right) {
            if (postorder[tmp++] < rootVal) {
                return false;
            }
        }
        // 对于当前root已经满足要求了 看左右子树是否满足
        return process(postorder, left, mid - 1) && process(postorder, mid, right - 1);
    }

    // todo 单调栈
    
};