/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
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
        if (root == nullptr)
            return;
        flatten(root->left);
        flatten(root->right);
        auto r = root->right;
        if (root->left != nullptr)
        {
            root->right = root->left;
            root->left = nullptr;
            while (root->right != nullptr)
            {
                root = root->right;
            }
            root->right = r;
        }
    }
};
