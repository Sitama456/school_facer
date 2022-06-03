/*
 * @Description: 
 * @Author: mzm
 * @Date: 2022-05-29 20:02:01
 * @LastEditTime: 2022-05-29 20:20:28
 * @LastEditors: mzm
 */
#include <vector>
struct ListNode
{
    int value;
    ListNode* next;
};


/**
 * @brief 将单链表按某值划分成左边小、中间相等、右边大的形式
 * 进阶要求:
 * 1) 调整后所有小于pivot的结点之间的相对顺序和调整前一致
 * 2) 调整后所有等于pivot的结点之间的相对顺序和调整前一致
 * 3) 调整后所有大于pivot的结点之间的相对顺序和调整前一致
 * 4) 时间复杂度 O(N) 空间复杂度 O(1)
 * 
 */
using namespace std;

/**
 * @brief 直接将结点地址放在数组里 partition
 * 
 * @param head 
 * @param pivot 
 */
void partitionList(ListNode* head, int pivot) {
    ListNode* cur = head;
    vector<ListNode*> nodes; 
    while (cur) {
        nodes.push_back(cur);
        cur = cur->next;
    }
    // partition 过程
}


ListNode* partitionList1(ListNode* head, int pivot) {
    ListNode* smallHead = nullptr;
    ListNode* smallTail = nullptr;
    ListNode* equalHead = nullptr;
    ListNode* equalTail = nullptr;
    ListNode* largerHead = nullptr;
    ListNode* largerTail = nullptr;

    ListNode* next = nullptr;
    while (head) {
        next = head->next;
        head->next = nullptr; 
        if (head->value < pivot) {
            if (smallHead == nullptr) {
                smallHead = head;
                smallTail = head;
            } else {
                smallTail->next = head;
                smallTail = head;
            }
        } else if (head->value == pivot) {
            if (equalHead == nullptr) {
                equalHead = head;
                equalTail = head;
            } else {
                equalTail->next = head;
                equalTail = head;
            }
        } else {
            if (largerHead == nullptr) {
                largerHead = head;
                largerTail = head;
            } else {
                largerTail->next = head;
                largerTail = head;
            }
        }
    }
    // 需要考虑是否有小于区域 是否有等于区域
    if (smallHead != nullptr) { // 如果有小于区域
        smallTail->next = equalHead;
        // 下一步谁去连大于区域的头 谁就是 equalTail
        equalTail = equalTail == nullptr ? smallTail : equalTail; 
    }
    if (equalTail != nullptr) {
        equalTail->next = largerHead;
    }
    return smallHead != nullptr ? smallHead : (equalHead != nullptr ? equalHead : largerHead);

}