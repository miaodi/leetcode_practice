/*
 * @lc app=leetcode id=515 lang=cpp
 *
 * [515] Find Largest Value in Each Tree Row
 *
 * https://leetcode.com/problems/find-largest-value-in-each-tree-row/description/
 *
 * algorithms
 * Medium (57.26%)
 * Total Accepted:    59K
 * Total Submissions: 103K
 * Testcase Example:  '[1,3,2,5,3,null,9]'
 *
 * You need to find the largest value in each row of a binary tree.
 * 
 * Example:
 * 
 * Input: 
 * 
 * ⁠         1
 * ⁠        / \
 * ⁠       3   2
 * ⁠      / \   \  
 * ⁠     5   3   9 
 * 
 * Output: [1, 3, 9]
 * 
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
    vector<int> largestValues(TreeNode *root)
    {
        vector<int> res;
        if (root == nullptr)
            return res;
        vector<TreeNode *> s;
        s.push_back(root);
        while (s.size() != 0)
        {
            int largest = INT_MIN;
            vector<TreeNode *> tmp;
            for (auto &i : s)
            {
                largest = max(largest, i->val);
                if (i->left != nullptr)
                    tmp.push_back(i->left);
                if (i->right != nullptr)
                    tmp.push_back(i->right);
            }
            res.push_back(largest);
            s = tmp;
        }
        return res;
    }
};
