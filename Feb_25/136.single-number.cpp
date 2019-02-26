/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 *
 * https://leetcode.com/problems/single-number/description/
 *
 * algorithms
 * Easy (58.91%)
 * Total Accepted:    415.2K
 * Total Submissions: 704.7K
 * Testcase Example:  '[2,2,1]'
 *
 * Given a non-empty array of integers, every element appears twice except for
 * one. Find that single one.
 * 
 * Note:
 * 
 * Your algorithm should have a linear runtime complexity. Could you implement
 * it without using extra memory?
 * 
 * Example 1:
 * 
 * 
 * Input: [2,2,1]
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [4,1,2,1,2]
 * Output: 4
 * 
 * 
 */
class Solution
{
  public:
    int singleNumber(vector<int> &nums)
    {
        // if(nums.size()==1) return nums[0];
        // // without extra memory
        // sort(nums.begin(), nums.end());
        // if (nums[0] != nums[1])
        //     return nums[0];
        // if (*(nums.end() - 1) != *(nums.end() - 2))
        //     return *(nums.end() - 1);
        // for (int i = 1; i < nums.size()-1; i++)
        // {
        //     if(nums[i]!=nums[i+1] && nums[i+1]!=nums[i+2]) return nums[i+1];
        // }
        // with extra memory
        sort(nums.begin(), nums.end());
        stack<int> s;
        for(auto i:nums){
            if(s.size()==0||s.top()!=i){
                s.push(i);
            }else if(s.top()==i){
                s.pop();
            }
        }
        return s.top();
    }
};
