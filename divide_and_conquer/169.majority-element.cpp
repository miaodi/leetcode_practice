/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */
class Solution
{
public:
    //divide and conquer
    int majorityElement(vector<int> &nums)
    {
        return majoritySub(nums, 0, nums.size() - 1);
    }
    int majoritySub(vector<int> &nums, int l, int r)
    {
        if (l == r)
            return nums[l];
        int m = (l + r) / 2;
        int lmaj = majoritySub(nums, l, m);
        int rmaj = majoritySub(nums, m + 1, r);
        if (lmaj == rmaj)
            return lmaj;
        int count = 0;
        for (int i = l; i <= r; i++)
        {
            if (nums[i] == lmaj)
                count++;
        }
        return count > (r - l + 1) / 2 ? lmaj : rmaj;
    }

    // int majorityElement(vector<int> &nums)
    // {
    //     int cur;
    //     int count = 0;
    //     for (auto i : nums)
    //     {
    //         if (count == 0)
    //         {
    //             cur = i;
    //             count++;
    //         }
    //         else
    //         {
    //             if (cur == i)
    //             {
    //                 count++;
    //             }
    //             else
    //             {
    //                 count--;
    //             }
    //         }
    //     }
    //     return cur;
    // }
};
