/*
 * @lc app=leetcode id=109 lang=cpp
 *
 * [109] Convert Sorted List to Binary Search Tree
 *
 * https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/
 *
 * algorithms
 * Medium (39.61%)
 * Total Accepted:    164.8K
 * Total Submissions: 416.2K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * Given a singly linked list where elements are sorted in ascending order,
 * convert it to a height balanced BST.
 * 
 * For this problem, a height-balanced binary tree is defined as a binary tree
 * in which the depth of the two subtrees of every node never differ by more
 * than 1.
 * 
 * Example:
 * 
 * 
 * Given the sorted linked list: [-10,-3,0,5,9],
 * 
 * One possible answer is: [0,-3,9,-10,null,5], which represents the following
 * height balanced BST:
 * 
 * ⁠     0
 * ⁠    / \
 * ⁠  -3   9
 * ⁠  /   /
 * ⁠-10  5
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
  public:
    TreeNode *sortedListToBST(ListNode *head)
    {
        auto size = count(head);
        return sortedListToBST1(head, size);
    }

    TreeNode *sortedListToBST1(ListNode *head, int size)
    {
        if (size == 0)
        {
            return nullptr;
        }
        else if (size == 1)
        {
            return new TreeNode(head->val);
        }
        else if (size == 2)
        {
            auto tmp = new TreeNode(head->val);
            tmp->right = new TreeNode(head->next->val);
            return tmp;
        }
        else if (size == 3)
        {
            auto tmp = new TreeNode(head->next->val);
            tmp->left = new TreeNode(head->val);
            tmp->right = new TreeNode(head->next->next->val);
            return tmp;
        }
        else
        {
            int mid = size / 2;
            auto it = head;
            for (int i = 0; i < mid; i++)
            {
                it = it->next;
            }

            auto tmp = new TreeNode(it->val);
            tmp->left = sortedListToBST1(head, mid);
            tmp->right = sortedListToBST1(it->next, size - mid - 1);
            return tmp;
        }
    }

    int count(ListNode *head)
    {
        int res = 0;
        while (head != nullptr)
        {
            res++;
            head = head->next;
        }
        return res;
    }
};
