/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        vector<int> dp(nums.size(), INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = 1; j <= nums[i] && j + i < nums.size(); j++)
            {
                dp[i + j] = min(dp[i + j], dp[i] + 1);
            }
        }
        return dp.back();
    }
};
