/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 *
 * https://leetcode.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (30.28%)
 * Total Accepted:    227.5K
 * Total Submissions: 751.2K
 * Testcase Example:  '[1,2,3]'
 *
 * Implement next permutation, which rearranges numbers into the
 * lexicographically next greater permutation of numbers.
 * 
 * If such arrangement is not possible, it must rearrange it as the lowest
 * possible order (ie, sorted in ascending order).
 * 
 * The replacement must be in-place and use only constant extra memory.
 * 
 * Here are some examples. Inputs are in the left-hand column and its
 * corresponding outputs are in the right-hand column.
 * 
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 * 
 */
class Solution
{
  public:
    void nextPermutation(vector<int> &nums)
    {
        if (nums.empty() || nums.size() == 1)
            return;
        bool last = true;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            last = last && nums[i] >= nums[i + 1];
        }
        if (last)
        {
            sort(nums.begin(), nums.end());
        }
        else
        {
            for (int i = nums.size() - 2; i >= 0; i--)
            {
                if (nums[i + 1] > nums[i])
                {
                    int k = i;
                    while (i < nums.size() - 1 && nums[i + 1] > nums[k])
                    {
                        i++;
                    }
                    swap(nums[k], nums[i]);
                    sort(nums.begin() + k + 1, nums.end());
                    break;
                }
            }
        }
    }
};
