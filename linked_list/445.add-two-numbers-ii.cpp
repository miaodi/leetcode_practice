/*
 * @lc app=leetcode id=445 lang=cpp
 *
 * [445] Add Two Numbers II
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
        stack<ListNode *> s1;
        stack<ListNode *> s2;

        while (l1 != nullptr)
        {
            s1.push(l1);
            l1 = l1->next;
        }
        while (l2 != nullptr)
        {
            s2.push(l2);
            l2 = l2->next;
        }
        int next = 0;
        ListNode *ln = nullptr;
        while (s1.size() || s2.size() || next)
        {
            int val = next;
            ListNode *p1 = nullptr, *p2 = nullptr;
            if (s1.size())
            {
                val += s1.top()->val;
                p1 = s1.top();
                s1.pop();
            }
            if (s2.size())
            {
                val += s2.top()->val;
                p2 = s2.top();
                s2.pop();
            }
            next = val / 10;
            if (p1)
            {
                p1->val = val % 10;
                p1->next = ln;
                ln = p1;
            }
            else if (p2)
            {
                p2->val = val % 10;
                p2->next = ln;
                ln = p2;
            }
            else
            {
                auto tmp = new ListNode(1);
                tmp->next = ln;
                ln = tmp;
            }
        }
        return ln;
    }
};
