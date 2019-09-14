/*
 * @lc app=leetcode id=450 lang=cpp
 *
 * [450] Delete Node in a BST
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
    TreeNode *deleteNode(TreeNode *&root, int key)
    {
        if (root == nullptr)
            return nullptr;

        auto l = deleteNode(root->left, key);
        auto r = deleteNode(root->right, key);

        if (root->val == key)
        {
            delete root;
            if (r != nullptr)
            {
                root = r;
                while (r->left != nullptr)
                {
                    r = r->left;
                }
                r->left = l;
            }
            else
            {
                root = l;
            }
        }
        return root;
    }
};
