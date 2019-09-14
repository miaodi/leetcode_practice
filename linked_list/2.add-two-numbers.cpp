/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *res = l1;
        int next = 0;
        ListNode *it1 = l1;
        ListNode *it2 = l2;
        while (true)
        {
            int val = it1->val + it2->val + next;
            next = val / 10;
            it1->val = val % 10;
            if (it1->next == nullptr)
            {
                it1->next = it2->next;
                break;
            }
            if (it2->next == nullptr)
            {
                break;
            }
            it1 = it1->next;
            it2 = it2->next;
        }
        while (it1->next != nullptr && next)
        {
            it1 = it1->next;
            int val = it1->val + next;
            next = val / 10;
            it1->val = val % 10;
        }
        if (next)
        {
            it1->next = new ListNode(1);
        }
        return res;
    }
};
