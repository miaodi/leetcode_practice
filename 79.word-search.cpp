/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 *
 * https://leetcode.com/problems/word-search/description/
 *
 * algorithms
 * Medium (30.29%)
 * Total Accepted:    249.4K
 * Total Submissions: 823.4K
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * Given a 2D board and a word, find if the word exists in the grid.
 * 
 * The word can be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring. The
 * same letter cell may not be used more than once.
 * 
 * Example:
 * 
 * 
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 * 
 * Given word = "ABCCED", return true.
 * Given word = "SEE", return true.
 * Given word = "ABCB", return false.
 * 
 * 
 */
class Solution
{
  public:
    bool exist(vector<vector<char>> &board, string word)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (helper(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
    bool helper(vector<vector<char>> &board, string &word, int i, int j, int pos)
    {
        if (pos == word.size())
        {
            return true;
        }

        if (i < 0 || j < 0 || i == board.size() || j == board[0].size())
            return false;
        if (word[pos] == board[i][j])
        {
            auto tmp = board[i][j];
            board[i][j] = '.';
            if (helper(board, word, i - 1, j, pos + 1) || helper(board, word, i + 1, j, pos + 1) || helper(board, word, i, j - 1, pos + 1) || helper(board, word, i, j + 1, pos + 1))
                return true;
            board[i][j] = tmp;
        }
        return false;
    }
};
