/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 *
 * https://leetcode.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (41.38%)
 * Total Accepted:    187.9K
 * Total Submissions: 454K
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
        sort(nums.begin(), nums.end());
        set<vector<int>> m;
        m.insert(vector<int>());
        // this portion is very important.
        {
            for (int i = 0; i < nums.size(); ++i)
            {
                set<vector<int>> tmp;
                for (auto j : m)
                {
                    j.push_back(nums[i]);
                    tmp.insert(j);
                }
                m.insert(tmp.begin(), tmp.end());
            }
        }
        vector<vector<int>> res;
        for (auto &i : m)
        {
            res.push_back(i);
        }
        return res;
    }
};
