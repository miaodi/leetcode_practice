/*
 * @lc app=leetcode id=377 lang=cpp
 *
 * [377] Combination Sum IV
 *
 * https://leetcode.com/problems/combination-sum-iv/description/
 *
 * algorithms
 * Medium (43.71%)
 * Total Accepted:    80K
 * Total Submissions: 183K
 * Testcase Example:  '[1,2,3]\n4'
 *
 * Given an integer array with all positive numbers and no duplicates, find the
 * number of possible combinations that add up to a positive integer target.
 * 
 * Example:
 * 
 * 
 * nums = [1, 2, 3]
 * target = 4
 * 
 * The possible combination ways are:
 * (1, 1, 1, 1)
 * (1, 1, 2)
 * (1, 2, 1)
 * (1, 3)
 * (2, 1, 1)
 * (2, 2)
 * (3, 1)
 * 
 * Note that different sequences are counted as different combinations.
 * 
 * Therefore the output is 7.
 * 
 * 
 * 
 * 
 * Follow up:
 * What if negative numbers are allowed in the given array?
 * How does it change the problem?
 * What limitation we need to add to the question to allow negative numbers?
 * 
 * Credits:
 * Special thanks to @pbrother for adding this problem and creating all test
 * cases.
 * 
 */
class Solution
{
  public:
    int combinationSum4(vector<int> &nums, int target)
    {
        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; ++i)
        {
            for (auto a : nums)
            {
                if (i >= a)
                    dp[i] += dp[i - a];
            }
        }
        return dp.back();
    }
    // DFS TML
    // void helper(vector<int> &nums, int target, int curr, int &res)
    // {
    //     if (curr == target)
    //     {
    //         res++;
    //         return;
    //     }
    //     else if (curr > target)
    //     {
    //         return;
    //     }
    //     else
    //     {
    //         for (auto i : nums)
    //         {
    //             auto tmp = i + curr;
    //             helper(nums, target, tmp, res);
    //         }
    //     }
    // }
};
