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
  protected:
    int s_x;
    int s_y;

  public:
    bool exist(vector<vector<char>> &board, string word)
    {
        s_x = board.size();
        s_y = board[0].size();
        for (int i = 0; i < s_x; i++)
        {
            for (int j = 0; j < s_y; j++)
            {
                if (helper(board, word, 0, i, j))
                    return true;
            }
        }
        return false;
    }
    bool helper(vector<vector<char>> &board, string &word, int i, int x, int y)
    {
        if (i == word.size())
        {
            return true;
        }
        else
        {
            if (x < 0 || x >= s_x || y < 0 || y >= s_y || board[x][y] != word[i])
            {
                return false;
            }
            auto t = board[x][y];
            board[x][y] = '0';
            // so wierd bool ref does not work but return bool works.
            bool tmp = helper(board, word, i + 1, x + 1, y) ||
                       helper(board, word, i + 1, x - 1, y) ||
                       helper(board, word, i + 1, x, y + 1) ||
                       helper(board, word, i + 1, x, y - 1);
            board[x][y] = t;
            return tmp;
        }
    }
};
