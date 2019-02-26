/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
 *
 * https://leetcode.com/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (33.98%)
 * Total Accepted:    178.3K
 * Total Submissions: 524.8K
 * Testcase Example:  '[1,2,3,4,5]\n2\n4'
 *
 * Reverse a linked list from position m to n. Do it in one-pass.
 * 
 * Note: 1 ≤ m ≤ n ≤ length of list.
 * 
 * Example:
 * 
 * 
 * Input: 1->2->3->4->5->NULL, m = 2, n = 4
 * Output: 1->4->3->2->5->NULL
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
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* start = new ListNode(0); //we a dummy start we don't need to consider corner case m==1;
        start->next = head;
        auto it = start;
        for(int i=0;i<m-1;i++){
            it=it->next;
        }
        auto h = it;
        stack<ListNode*> s;
        for(int i=m;i<=n;i++){
            it=it->next;
            s.push(it);
        }
        ListNode* b = it->next;
        while(!s.empty()){
            h->next = s.top();
            s.pop();
            h=h->next;
        }
        h->next = b;
        auto res = start->next;
        delete start;
        return res;
    }
};

