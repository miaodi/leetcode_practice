/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
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
    int minDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int l = minDepth(root->left);
        int r = minDepth(root->right);
        if (l == 0 && r == 0)
            return 1;
        if (l == 0)
            return r + 1;
        if (r == 0)
            return l + 1;
        return min(l, r) + 1;
    }
};
