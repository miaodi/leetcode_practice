/*
 * @lc app=leetcode id=222 lang=cpp
 *
 * [222] Count Complete Tree Nodes
 *
 * https://leetcode.com/problems/count-complete-tree-nodes/description/
 *
 * algorithms
 * Medium (31.45%)
 * Total Accepted:    107.6K
 * Total Submissions: 341.9K
 * Testcase Example:  '[1,2,3,4,5,6]'
 *
 * Given a complete binary tree, count the number of nodes.
 * 
 * Note: 
 * 
 * Definition of a complete binary tree from Wikipedia:
 * In a complete binary tree every level, except possibly the last, is
 * completely filled, and all nodes in the last level are as far left as
 * possible. It can have between 1 and 2^h nodes inclusive at the last level
 * h.
 * 
 * Example:
 * 
 * 
 * Input: 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   3
 * ⁠/ \  /
 * 4  5 6
 * 
 * Output: 6
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
    int countNodes(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int left = 0, right = 0;
        auto lp = root;
        auto rp = root;
        while (lp->left != nullptr)
        {
            lp = lp->left;
            left++;
        }
        while (rp->right != nullptr)
        {
            rp = rp->right;
            right++;
        }
        if (left == right)
        {
            return pow(2, left + 1) - 1;
        }
        else
        {
            return countNodes(root->left) + countNodes(root->right)+1;// dont forget to add 111111111111111111111111111111111
        }
    }
};
