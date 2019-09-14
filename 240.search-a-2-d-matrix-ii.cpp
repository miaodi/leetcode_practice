/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 */
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        int i = 0;
        int j = matrix[0].size() - 1;
        while (i < matrix.size() && j >= 0)
        {
            if (matrix[i][j] < target)
            {
                i++;
            }
            else if (matrix[i][j] > target)
            {
                j--;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};
