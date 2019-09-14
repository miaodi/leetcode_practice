/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        auto pseudo = new ListNode(0);
        pseudo->next = head;

        auto it = pseudo;
        auto ahead_it = pseudo;
        while (n + 1)
        {
            ahead_it = ahead_it->next;
            n--;
        }
        while (ahead_it != nullptr)
        {
            ahead_it = ahead_it->next;
            it = it->next;
        }
        auto tmp = it->next;
        it->next = it->next->next;
        delete tmp;
        return pseudo->next;
    }
};
