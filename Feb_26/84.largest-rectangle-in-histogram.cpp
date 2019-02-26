/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 *
 * https://leetcode.com/problems/largest-rectangle-in-histogram/description/
 *
 * algorithms
 * Hard (30.19%)
 * Total Accepted:    157.8K
 * Total Submissions: 522.8K
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * Given n non-negative integers representing the histogram's bar height where
 * the width of each bar is 1, find the area of largest rectangle in the
 * histogram.
 * 
 * 
 * 
 * 
 * Above is a histogram where width of each bar is 1, given height =
 * [2,1,5,6,2,3].
 * 
 * 
 * 
 * 
 * The largest rectangle is shown in the shaded area, which has area = 10
 * unit.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: [2,1,5,6,2,3]
 * Output: 10
 * 
 * 
 */
class Solution
{
  public:
    // // O(n^2) version
    // int largestRectangleArea(vector<int> &heights)
    // {

    //     int res = 0;
    //     for (int i = 0; i < heights.size(); i++)
    //     {
    //         int curr_height = heights[i];
    //         for (int j = i; j >= 0; j--)
    //         {
    //             if (heights[j] == 0)
    //                 break;
    //             curr_height = min(curr_height, heights[j]);
    //             res = max(res, curr_height * (i - j + 1));
    //         }
    //     }
    //     return res;
    // }
    // O(n) version *****
    int largestRectangleArea(vector<int> &heights)
    {
        heights.push_back(-1);
        heights.insert(heights.begin(),-1);
        int res = 0;
        stack<int> s; // Index
        s.push(0);

        for (int i = 1; i < heights.size(); i++)
        {
            while(heights[i]<heights[s.top()]){
                int h = heights[s.top()];
                s.pop();
                res = max(res, h*(i-s.top()-1));
            }
            s.push(i);
        }
        return res;
    }
};
