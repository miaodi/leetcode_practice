/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 *
 * https://leetcode.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (41.98%)
 * Total Accepted:    197K
 * Total Submissions: 469K
 * Testcase Example:  '[1,2,2]'
 *
 * Given a collection of integers that might contain duplicates, nums, return
 * all possible subsets (the power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,2]
 * Output:
 * [
 * ⁠ [2],
 * ⁠ [1],
 * ⁠ [1,2,2],
 * ⁠ [2,2],
 * ⁠ [1,2],
 * ⁠ []
 * ]
 * 
 * 
 */
class Solution
{
  public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        set<vector<int>> res;
        vector<int> cur;
        res.insert(cur);
        sort(nums.begin(), nums.end());
        helper(res, cur, 0, nums);
        vector<vector<int>> ress;
        for (auto &i : res)
        {
            ress.push_back(i);
        }
        return ress;
    }
    void helper(set<vector<int>> &res, vector<int> &cur, int pos, vector<int> &nums)
    {
        if (pos == nums.size())
            return;
        for (int i = pos; i < nums.size(); i++)
        {
            auto tmp = cur;
            tmp.push_back(nums[i]);
            auto re = res.insert(tmp);
            if (re.second)
            {
                helper(res, tmp, i + 1, nums);
            }
        }
    }
};
