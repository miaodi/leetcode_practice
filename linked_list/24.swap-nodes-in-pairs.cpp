/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// need more practice
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *res = new ListNode(0);
        auto it_prev = res;
        it_prev->next = head;
        auto it = head;
        while (it != nullptr && it->next != nullptr)
        {
            it_prev->next = it->next;
            auto tmp = it->next->next;
            it_prev->next->next = it;
            it_prev = it_prev->next->next;
            it = tmp;
            it_prev->next = it;
        }
        return res->next;
    }
};
