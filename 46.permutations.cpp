/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (54.42%)
 * Total Accepted:    362.7K
 * Total Submissions: 666K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a collection of distinct integers, return all possible permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3]
 * Output:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 * 
 */
class Solution
{
  public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<bool> activate(nums.size(), true);
        vector<int> cur;
        helper(nums, activate, res, cur);
        return res;
    }
    void helper(vector<int> &nums, vector<bool> &activate, vector<vector<int>> &res, vector<int> &cur)
    {
        if (cur.size() == nums.size())
        {
            res.push_back(cur);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (activate[i])
            {
                auto tmp = cur;
                tmp.push_back(nums[i]);
                activate[i] = false;
                helper(nums, activate, res, tmp);
                activate[i] = true;
            }
        }
    }
};
