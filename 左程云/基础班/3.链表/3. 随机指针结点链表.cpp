/*
 * @Description: 
 * @Author: mzm
 * @Date: 2022-05-29 20:21:09
 * @LastEditTime: 2022-05-29 20:26:45
 * @LastEditors: mzm
 */
#include <vector>
#include <unordered_map>
using namespace std;

/**
 * @brief 一种特殊的单链表结点描述如下
 * rand 指针是单链表结点结构中新增的指针，rand可能指向链表中的任意一个结点，也可能指向null。
 * 给定一个由Node结点组成的无环单链表的头结点head。请实现一个函数完成这个链表的复制，并返回
 * 复制的新链表的头结点。
 * 
 */

struct Node
{
    int value;
    Node* next;
    Node* rand;
    Node(int value) : value(value), next(nullptr), rand(nullptr) { }
};


/**
 * @brief 用 map 做 
 * 
 * @param head 
 * @return Node* 
 */
Node* copyListNode(Node* head) {
    // 使用map：老结点->新结点
    Node* cur = head;
    unordered_map<Node*, Node*> mapper;
    while (cur) {
        Node* newNode = new Node();
        newNode->value = cur->value;
        mapper.insert(make_pair(cur, newNode));
        cur = cur->next;
    }
    cur = head;
    while (cur) {
        Node* newNode = mapper[cur];
        newNode->next = mapper[cur->next];
        newNode->rand = mapper[cur->rand];
        cur = cur->next;
    }
    return mapper[head];
}

Node* copyListNode1(Node* head) {
    if (head == nullptr) { 
        return nullptr;
    }
    Node* cur = head;
    Node* next = nullptr; 
    // 在老节点后面直接串新节点
    while (cur) {
        next = cur->next;
        cur->next = new Node(cur->value);
        cur->next->next = next;
        cur = next;
    }
    // 此时是 1->1_->2->2_->...
    cur = head;
    Node* curCopy = nullptr;
    while(cur) {
        next = cur->next->next;
        curCopy = cur->next;
        curCopy->rand = cur->rand ? cur->rand->next : nullptr;
        cur = next;
    }
    Node* res = head->next;
    cur = head;
    while (cur) {
        next = cur->next->next;
        curCopy = cur->next;
        cur->next = next;
        curCopy->next = next ? next->next : nullptr;
        cur = cur->next;
    }
    return res;
}