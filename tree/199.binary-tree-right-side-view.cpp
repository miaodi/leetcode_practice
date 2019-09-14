/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
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
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> res;
        if (root == nullptr)
            return res;

        vector<TreeNode *> q;
        q.push_back(root);
        int count = 0;
        while (!q.empty())
        {
            vector<TreeNode *> tmp;
            for (auto &i : q)
            {
                if (res.size() == count)
                {
                    res.push_back(i->val);
                }

                if (i->right != nullptr)
                    tmp.push_back(i->right);
                if (i->left != nullptr)
                    tmp.push_back(i->left);
            }
            q = move(tmp);
            count++;
        }
        return res;
    }
};
