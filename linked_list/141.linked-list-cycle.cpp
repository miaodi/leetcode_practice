/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
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
    bool hasCycle(ListNode *head)
    {
        if (head == nullptr)
            return false;
        auto slow = head;
        auto fast = head;
        while (true)
        {
            slow = slow->next;
            fast = fast->next;
            if (fast == nullptr)
            {
                return false;
            }
            fast = fast->next;
            if (fast == nullptr)
            {
                return false;
            }
            if (slow == fast)
                return true;
        }
        return false;
    }
};
