/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (25.60%)
 * Total Accepted:    389.2K
 * Total Submissions: 1.5M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * 
 * Find the median of the two sorted arrays. The overall run time complexity
 * should be O(log (m+n)).
 * 
 * You may assume nums1 and nums2 cannot be both empty.
 * 
 * Example 1:
 * 
 * 
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * The median is 2.0
 * 
 * 
 * Example 2:
 * 
 * 
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * The median is (2 + 3)/2 = 2.5
 * 
 * 
 */
class Solution
{
  public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> nums(nums1.size() + nums2.size());
        int i1 = 0, i2 = 0;
        for (int i = 0; i < nums.size(); i++)
        {

            if (i2 >= nums2.size())
            {
                nums[i] = nums1[i1];
                i1++;
                continue;
            }
            if (i1 >= nums1.size())
            {
                nums[i] = nums2[i2];
                i2++;
                continue;
            }
            if (nums1[i1] <= nums2[i2])
            {
                nums[i] = nums1[i1];
                i1++;
            }
            else
            {
                nums[i] = nums2[i2];
                i2++;
            }
        }
        if (nums.size() % 2 == 1)
            return nums[nums.size() / 2];
        return 1.0 * (nums[nums.size() / 2] + nums[nums.size() / 2 - 1]) / 2;
    }
};
