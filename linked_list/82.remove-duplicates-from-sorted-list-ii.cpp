/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
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
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *res = new ListNode(0);
        auto it_prev = res;
        auto it = head;
        res->next = head;
        while (it != nullptr)
        {
            int val = it->val;
            if (it->next == nullptr || it->next->val != val)
            {
                it_prev->next = it;
                it_prev = it_prev->next;
                it = it->next;
            }
            else
            {
                while (it != nullptr && it->val == val)
                {
                    it = it->next;
                }
            }
        }
        it_prev->next = it;
        return res->next;
    }
};
