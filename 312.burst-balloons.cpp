/*
 * @lc app=leetcode id=312 lang=cpp
 *
 * [312] Burst Balloons
 *
 * https://leetcode.com/problems/burst-balloons/description/
 *
 * algorithms
 * Hard (46.33%)
 * Total Accepted:    57.7K
 * Total Submissions: 124.5K
 * Testcase Example:  '[3,1,5,8]'
 *
 * Given n balloons, indexed from 0 to n-1. Each balloon is painted with a
 * number on it represented by array nums. You are asked to burst all the
 * balloons. If the you burst balloon i you will get nums[left] * nums[i] *
 * nums[right] coins. Here left and right are adjacent indices of i. After the
 * burst, the left and right then becomes adjacent.
 * 
 * Find the maximum coins you can collect by bursting the balloons wisely.
 * 
 * Note:
 * 
 * 
 * You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can
 * not burst them.
 * 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100
 * 
 * 
 * Example:
 * 
 * 
 * Input: [3,1,5,8]
 * Output: 167 
 * Explanation: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  -->
 * []
 * coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
 * 
 */
class Solution
{
  public:
    int maxCoins(vector<int> &nums)
    {
        int size = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));
        int res = 0;
        for (int len = 0; len < size; len++)
        {
            for (int i = 1; i + len - 1 < size; i++)
            {
                for (int j = 0; j <= len; j++)
                {
                    dp[i][i + len] = max(dp[i][i + len], dp[i][i + j - 1] + dp[i + j + 1][i + len] + nums[i - 1] * nums[i + j] * nums[i + len + 1]);
                }
                res = max(res, dp[i][i + len]);
            }
        }
        return res;
    }
};
