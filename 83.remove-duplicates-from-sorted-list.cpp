/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
 *
 * algorithms
 * Easy (42.15%)
 * Total Accepted:    312.1K
 * Total Submissions: 740.4K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a sorted linked list, delete all duplicates such that each element
 * appear only once.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->1->2
 * Output: 1->2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 1->1->2->3->3
 * Output: 1->2->3
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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if(head==nullptr) return head;
        set<int> s;
        ListNode *it = head;
        s.insert(head->val);
        while (it->next != nullptr)
        {
            auto itt = s.find((it->next)->val);
            if (itt != s.end())
            {
                auto temp = it->next;
                it->next = temp->next;
                delete temp;
            }
            else
            {
                s.insert((it->next)->val);
                it = it->next;
            }
        }
        return head;
    }
};
