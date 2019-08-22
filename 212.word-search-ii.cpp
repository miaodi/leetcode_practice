/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
 *
 * https://leetcode.com/problems/word-search-ii/description/
 *
 * algorithms
 * Hard (28.10%)
 * Total Accepted:    106.7K
 * Total Submissions: 379.1K
 * Testcase Example:  '[["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]]\n["oath","pea","eat","rain"]'
 *
 * Given a 2D board and a list of words from the dictionary, find all words in
 * the board.
 * 
 * Each word must be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring. The
 * same letter cell may not be used more than once in a word.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: 
 * board = [
 * ⁠ ['o','a','a','n'],
 * ⁠ ['e','t','a','e'],
 * ⁠ ['i','h','k','r'],
 * ⁠ ['i','f','l','v']
 * ]
 * words = ["oath","pea","eat","rain"]
 * 
 * Output: ["eat","oath"]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * All inputs are consist of lowercase letters a-z.
 * The values of words are distinct.
 * 
 * 
 */
class Solution
{
  public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        vector<string> res;
        for (auto &word : words)
        {
            for (int i = 0; i < board.size(); i++)
            {
                bool checker = false;
                for (int j = 0; j < board[0].size(); j++)
                {
                    if (helper(board, word, i, j, 0))
                    {
                        res.push_back(word);
                        checker = true;
                        break;
                    }
                }
                if (checker)
                    break;
            }
        }
        return res;
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
            {
                board[i][j] = tmp;
                return true;
            }
            else
            {
                board[i][j] = tmp;
            }
        }
        return false;
    }
};
