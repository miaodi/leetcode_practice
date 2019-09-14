/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *res = new ListNode(0);
        ListNode *ress = res;
        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val < l2->val)
            {
                res->next = l1;
                l1 = l1->next;
            }
            else
            {
                res->next = l2;
                l2 = l2->next;
            }
            res = res->next;
        }
        if (l1 != nullptr)
        {
            res->next = l1;
        }
        else
        {
            res->next = l2;
        }
        return ress->next;
    }
};
