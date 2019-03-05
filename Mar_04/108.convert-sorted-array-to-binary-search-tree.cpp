/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
 *
 * https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
 *
 * algorithms
 * Easy (49.28%)
 * Total Accepted:    239K
 * Total Submissions: 485K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * Given an array where elements are sorted in ascending order, convert it to a
 * height balanced BST.
 * 
 * For this problem, a height-balanced binary tree is defined as a binary tree
 * in which the depth of the two subtrees of every node never differ by more
 * than 1.
 * 
 * Example:
 * 
 * 
 * Given the sorted array: [-10,-3,0,5,9],
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
    TreeNode *sortedArrayToBST(vector<int> &num)
    {
        return sortedArrayToBST1(num.begin(), num.end());
    }
    TreeNode *sortedArrayToBST1(vector<int>::iterator b, vector<int>::iterator e)
    {
        if (e - b == 0)
            return nullptr;
        if (e - b == 1)
            return new TreeNode(*b);
        if (e - b == 2)
        {
            auto tmp = new TreeNode(*b);
            tmp->right = new TreeNode(*(b + 1));
            return tmp;
        }
        if (e - b == 3)
        {
            auto tmp = new TreeNode(*(b + 1));
            tmp->right = new TreeNode(*(b + 2));
            tmp->left = new TreeNode(*(b));
            return tmp;
        }
        int mid = (e - b) / 2;
        auto tmp = new TreeNode(*(b + mid));
        tmp->left = sortedArrayToBST1(b, b + mid);
        tmp->right = sortedArrayToBST1(b + mid + 1, e);
        return tmp;
    }
};
