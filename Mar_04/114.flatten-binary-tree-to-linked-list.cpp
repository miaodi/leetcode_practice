/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
 *
 * https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/
 *
 * algorithms
 * Medium (41.12%)
 * Total Accepted:    220.5K
 * Total Submissions: 536.2K
 * Testcase Example:  '[1,2,5,3,4,null,6]'
 *
 * Given a binary tree, flatten it to a linked list in-place.
 * 
 * For example, given the following tree:
 * 
 * 
 * ⁠    1
 * ⁠   / \
 *  ⁠ 2   5
 *  ⁠/ \   \
 * 3   4   6
 * 
 * 
 * The flattened tree should look like:
 * 
 * 
 * 1
 *  ⁠\
 * ⁠  2
 * ⁠   \
 * ⁠    3
 * ⁠     \
 * ⁠      4
 * ⁠       \
 * ⁠        5
 * ⁠         \
 * ⁠          6
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

    void flatten(TreeNode *root)
    {
        if (root != nullptr)
        {
            flatten(root->left);
            flatten(root->right);
            auto right = root->right;
            auto it = root;
            if (root->left != nullptr)
            {
                root->right = root->left;
                root->left = nullptr;// it's important to reset left to nullptr shabi ti
                while (it->right != nullptr)
                {
                    it = it->right;
                }
            }
            if (right != nullptr)
            {
                it->right = right;
            }
        }
    }
};
