/*
 * @lc app=leetcode id=137 lang=cpp
 *
 * [137] Single Number II
 *
 * https://leetcode.com/problems/single-number-ii/description/
 *
 * algorithms
 * Medium (45.08%)
 * Total Accepted:    157.5K
 * Total Submissions: 349.3K
 * Testcase Example:  '[2,2,3,2]'
 *
 * Given a non-empty array of integers, every element appears three times
 * except for one, which appears exactly once. Find that single one.
 * 
 * Note:
 * 
 * Your algorithm should have a linear runtime complexity. Could you implement
 * it without using extra memory?
 * 
 * Example 1:
 * 
 * 
 * Input: [2,2,3,2]
 * Output: 3
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [0,1,0,1,0,1,99]
 * Output: 99
 * 
 */
class Solution
{
  public:
    int singleNumber(vector<int> &nums)
    {
        map<int, int> m;
        for (auto i : nums)
        {
            auto it = m.find(i);
            if (it != m.end())
            {
                it->second++;
                if (it->second == 3)
                    m.erase(it);
            }else{
                m[i]=1;
            }
        }
        return m.begin()->first;
    }
};
