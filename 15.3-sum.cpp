/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        if (nums.size() < 3)
            return res;

        for (int start = 0; start < nums.size() - 2;)
        {
            int end = nums.size() - 1;
            int mid = start + 1;
            while (mid < end)
            {
                int sum = nums[start] + nums[mid] + nums[end];
                if (sum < 0)
                {
                    mid++;
                }
                else if (sum > 0)
                {
                    end--;
                }
                else
                {
                    while (mid < end && nums[mid] == nums[mid + 1])
                    {
                        mid++;
                    }
                    while (end > mid && nums[end] == nums[end - 1])
                    {
                        end--;
                    }
                    res.emplace_back(vector<int>{nums[start], nums[mid], nums[end]});
                    mid++;
                    end--;
                }
            }
            while (start < nums.size() - 3 && nums[start] == nums[start + 1])
            {
                start++;
            }
            start++;
        }
        return res;
    }
};
