/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 *
 * https://leetcode.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (33.09%)
 * Total Accepted:    346K
 * Total Submissions: 1M
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * Merge k sorted linked lists and return it as one sorted list. Analyze and
 * describe its complexity.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * Output: 1->1->2->3->4->4->5->6
 * 
 * 
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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        auto dummy = new ListNode(0);
        auto it = dummy;
        while (true)
        {
            int v = INT_MAX;
            int ind = -1;
            for (int i = 0; i < lists.size(); i++)
            {
                if (lists[i] != nullptr && lists[i]->val < v)
                {
                    v = lists[i]->val;
                    ind = i;
                }
            }
            if (v == INT_MAX)
                break;
            it->next = lists[ind];
            lists[ind] = lists[ind]->next;
            it = it->next;
        }
        return dummy->next;
    }
};
