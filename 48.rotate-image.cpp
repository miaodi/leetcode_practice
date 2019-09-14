/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        if (matrix.size() <= 1)
            return;

        for (int i = 0; i < matrix.size() / 2; i++)
        {
            for (int j = i; j < matrix.size() - i - 1; j++)
            {
                int tmp;
                tmp = matrix[j][matrix.size() - 1 - i];
                matrix[j][matrix.size() - 1 - i] = matrix[i][j];
                int tmp2 = matrix[matrix.size() - 1 - i][matrix.size() - 1 - j];
                matrix[matrix.size() - 1 - i][matrix.size() - 1 - j] = tmp;

                tmp = matrix[matrix.size() - 1 - j][i];
                matrix[matrix.size() - 1 - j][i] = tmp2;

                matrix[i][j] = tmp;
            }
        }
    }
};
