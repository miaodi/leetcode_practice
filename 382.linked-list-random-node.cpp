/*
 * @lc app=leetcode id=382 lang=cpp
 *
 * [382] Linked List Random Node
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
    ListNode *h;
    int s;

public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode *head) : h(head)
    {
        s = size();
    }

    int size() const
    {
        int res = 0;
        auto it = h;
        while (it != nullptr)
        {
            res++;
            it = it->next;
        }
        return res;
    }

    /** Returns a random node's value. */
    int getRandom()
    {
        int step = rand() % s;

        auto it = h;
        while (step != 0)
        {
            it = it->next;
            step--;
        }
        return it->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
