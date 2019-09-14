/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */
class Solution
{
public:
    // int findKthLargest(vector<int> &nums, int k)
    // {
    //     sort(nums.begin(), nums.end(), std::greater<int>());
    //     return nums[k - 1];
    // }
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int num : nums)
        {
            pq.push(num);
            if (pq.size() > k)
            {
                pq.pop();
            }
        }
        return pq.top();
    }
};
