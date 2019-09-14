/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    // // iterative
    // ListNode *reverseList(ListNode *head)
    // {
    //     if (head == nullptr || head->next == nullptr)
    //         return head;
    //     auto it = head->next;
    //     head->next = nullptr;
    //     while (it != nullptr)
    //     {
    //         auto tmp = it->next;
    //         it->next = head;
    //         head = it;
    //         it = tmp;
    //     }
    //     return head;
    // }

    //recursive
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        auto it = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return it;
    }
};
