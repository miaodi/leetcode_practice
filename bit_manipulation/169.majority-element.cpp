/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */
//Boyer-Moore Voting Algorithm
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int count = 0;
        int cur;
        for (auto i : nums)
        {
            if (count == 0)
            {
                cur = i;
                count++;
            }
            else
            {
                count += (cur == i) ? 1 : -1;
            }
        }
        return cur;
    }
};
