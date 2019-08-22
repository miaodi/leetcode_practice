/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 *
 * https://leetcode.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (39.90%)
 * Total Accepted:    233.9K
 * Total Submissions: 585.8K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a collection of numbers that might contain duplicates, return all
 * possible unique permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,1,2]
 * Output:
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
 * ]
 * 
 * 
 */
class Solution
{
  public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        set<vector<int>> res;
        vector<bool> activate(nums.size(), true);
        vector<int> cur;
        helper(nums, activate, res, cur);
        vector<vector<int>> ress;
        for (auto &i : res)
        {
            ress.push_back(move(i));
        }
        return ress;
    }
    void helper(vector<int> &nums, vector<bool> &activate, set<vector<int>> &res, vector<int> &cur)
    {
        if (cur.size() == nums.size())
        {
            res.insert(cur);
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
