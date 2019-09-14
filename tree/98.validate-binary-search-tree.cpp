/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
    bool isValidBST(TreeNode *root)
    {
        TreeNode *minp, *maxp;
        return helper(root, minp, maxp);
    }
    bool helper(TreeNode *root, TreeNode *&minp, TreeNode *&maxp)
    {
        if (root == nullptr)
            return true;
        TreeNode *lmin = nullptr, *lmax = nullptr, *rmin = nullptr, *rmax = nullptr;
        auto l = helper(root->left, lmin, lmax);
        auto r = helper(root->right, rmin, rmax);
        if (!l || !r)
            return false;
        if ((lmax == nullptr || root->val > lmax->val) && (rmin == nullptr || root->val < rmin->val))
        {
            lmin == nullptr ? minp = root : minp = lmin;
            rmax == nullptr ? maxp = root : maxp = rmax;
            return true;
        }
        return false;
    }
};
