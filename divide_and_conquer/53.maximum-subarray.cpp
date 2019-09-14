/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */
class Solution
{
public:
    // divide and conquer
    // int maxSubArray(vector<int> &nums)
    // {
    //     return maxSub(nums, 0, nums.size() - 1);
    // }

    // int maxCross(vector<int> &nums, int l, int m, int r)
    // {
    //     int rsum = INT_MIN;
    //     int lsum = INT_MIN;
    //     int sum = 0;

    //     for (int i = m; i >= l; i--)
    //     {
    //         sum += nums[i];
    //         lsum = max(lsum, sum);
    //     }
    //     sum = 0;
    //     for (int i = m + 1; i <= r; i++)
    //     {
    //         sum += nums[i];
    //         rsum = max(rsum, sum);
    //     }
    //     return lsum + rsum;
    // }
    // int maxSub(vector<int> &nums, int l, int r)
    // {
    //     if (l == r)
    //     {
    //         return nums[l];
    //     }
    //     int mid = (l + r) / 2;
    //     return max(maxCross(nums, l, mid, r), max(maxSub(nums, l, mid), maxSub(nums, mid + 1, r)));
    // }

    int maxSubArray(vector<int> &nums)
    {
        int res = INT_MIN;
        int sum = 0;
        for (auto i : nums)
        {
            sum += i;
            res = max(res, sum);
            if (sum < 0)
                sum = 0;
        }
        return res;
    }
};
