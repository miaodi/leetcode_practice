/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 *
 * https://leetcode.com/problems/target-sum/description/
 *
 * algorithms
 * Medium (44.84%)
 * Total Accepted:    85.3K
 * Total Submissions: 190.3K
 * Testcase Example:  '[1,1,1,1,1]\n3'
 *
 * 
 * You are given a list of non-negative integers, a1, a2, ..., an, and a
 * target, S. Now you have 2 symbols + and -. For each integer, you should
 * choose one from + and - as its new symbol.
 * ⁠
 * 
 * Find out how many ways to assign symbols to make sum of integers equal to
 * target S.  
 * 
 * 
 * Example 1:
 * 
 * Input: nums is [1, 1, 1, 1, 1], S is 3. 
 * Output: 5
 * Explanation: 
 * 
 * -1+1+1+1+1 = 3
 * +1-1+1+1+1 = 3
 * +1+1-1+1+1 = 3
 * +1+1+1-1+1 = 3
 * +1+1+1+1-1 = 3
 * 
 * There are 5 ways to assign symbols to make the sum of nums be target 3.
 * 
 * 
 * 
 * Note:
 * 
 * The length of the given array is positive and will not exceed 20. 
 * The sum of elements in the given array will not exceed 1000.
 * Your output answer is guaranteed to be fitted in a 32-bit integer.
 * 
 * 
 */
class Solution
{
  public:
    int findTargetSumWays(vector<int> &nums, int S)
    {
        if (nums.size() == 0)
            return 0;
        int sum = 0;
        for (auto i : nums)
        {
            sum += i;
        }
        int res = 0;
        if (sum == S)
            res++;
        helper(nums, S, 0, res, sum);
        return res;
    }
    void helper(vector<int> &nums, int S, int pos, int &res, int sum)
    {
        for (int i = pos; i < nums.size(); i++)
        {
            auto tmp = sum;
            tmp -= 2 * nums[i];
            if (tmp == S)
            {
                res++;
            }
            if (tmp >= S)
                helper(nums, S, i + 1, res, tmp);
        }
    }
};
