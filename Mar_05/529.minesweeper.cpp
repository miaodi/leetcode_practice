/*
 * @lc app=leetcode id=529 lang=cpp
 *
 * [529] Minesweeper
 *
 * https://leetcode.com/problems/minesweeper/description/
 *
 * algorithms
 * Medium (51.82%)
 * Total Accepted:    29K
 * Total Submissions: 56K
 * Testcase Example:  '[["E","E","E","E","E"],["E","E","M","E","E"],["E","E","E","E","E"],["E","E","E","E","E"]]\n[3,0]'
 *
 * Let's play the minesweeper game (Wikipedia, online game)!
 * 
 * You are given a 2D char matrix representing the game board. 'M' represents
 * an unrevealed mine, 'E' represents an unrevealed empty square, 'B'
 * represents a revealed blank square that has no adjacent (above, below, left,
 * right, and all 4 diagonals) mines, digit ('1' to '8') represents how many
 * mines are adjacent to this revealed square, and finally 'X' represents a
 * revealed mine.
 * 
 * Now given the next click position (row and column indices) among all the
 * unrevealed squares ('M' or 'E'), return the board after revealing this
 * position according to the following rules:
 * 
 * 
 * If a mine ('M') is revealed, then the game is over - change it to 'X'.
 * If an empty square ('E') with no adjacent mines is revealed, then change it
 * to revealed blank ('B') and all of its adjacent unrevealed squares should be
 * revealed recursively.
 * If an empty square ('E') with at least one adjacent mine is revealed, then
 * change it to a digit ('1' to '8') representing the number of adjacent
 * mines.
 * Return the board when no more squares will be revealed.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 
 * 
 * [['E', 'E', 'E', 'E', 'E'],
 * ⁠['E', 'E', 'M', 'E', 'E'],
 * ⁠['E', 'E', 'E', 'E', 'E'],
 * ⁠['E', 'E', 'E', 'E', 'E']]
 * 
 * Click : [3,0]
 * 
 * Output: 
 * 
 * [['B', '1', 'E', '1', 'B'],
 * ⁠['B', '1', 'M', '1', 'B'],
 * ⁠['B', '1', '1', '1', 'B'],
 * ⁠['B', 'B', 'B', 'B', 'B']]
 * 
 * Explanation:
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 
 * 
 * [['B', '1', 'E', '1', 'B'],
 * ⁠['B', '1', 'M', '1', 'B'],
 * ⁠['B', '1', '1', '1', 'B'],
 * ⁠['B', 'B', 'B', 'B', 'B']]
 * 
 * Click : [1,2]
 * 
 * Output: 
 * 
 * [['B', '1', 'E', '1', 'B'],
 * ⁠['B', '1', 'X', '1', 'B'],
 * ⁠['B', '1', '1', '1', 'B'],
 * ⁠['B', 'B', 'B', 'B', 'B']]
 * 
 * Explanation:
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The range of the input matrix's height and width is [1,50].
 * The click position will only be an unrevealed square ('M' or 'E'), which
 * also means the input board contains at least one clickable square.
 * The input board won't be a stage when game is over (some mines have been
 * revealed).
 * For simplicity, not mentioned rules should be ignored in this problem. For
 * example, you don't need to reveal all the unrevealed mines when the game is
 * over, consider any cases that you will win the game or flag any squares.
 * 
 * 
 */
// again a BFS case. 
class Solution
{
  public:
    vector<vector<char>> updateBoard(vector<vector<char>> &board, vector<int> &click)
    {
        if (board[click[0]][click[1]] == 'M')
        {
            board[click[0]][click[1]] = 'X';
            return board;
        }
        int x = click[0];
        int y = click[1];
        vector<pair<int, int>> qq;
        qq.push_back(make_pair(click[0], click[1]));
        while (qq.size() != 0)
        {
            vector<pair<int, int>> tmp;
            for (auto &i : qq)
            {
                array<pair<int, int>, 8> neighbors;
                neighbors[0] = make_pair(i.first, i.second + 1);
                neighbors[1] = make_pair(i.first, i.second - 1);
                neighbors[2] = make_pair(i.first - 1, i.second);
                neighbors[3] = make_pair(i.first + 1, i.second);
                neighbors[4] = make_pair(i.first + 1, i.second - 1);
                neighbors[5] = make_pair(i.first + 1, i.second + 1);
                neighbors[6] = make_pair(i.first - 1, i.second - 1);
                neighbors[7] = make_pair(i.first - 1, i.second + 1);
                int m = 0;
                for (auto &j : neighbors)
                {
                    if (j.first >= 0 && j.first < board.size() && j.second >= 0 && j.second < board[0].size())
                    {
                        if (board[j.first][j.second] == 'M')
                        {
                            m++;
                        }
                    }
                }
                if (m == 0)
                {
                    if (board[i.first][i.second] == 'E')
                    {

                        board[i.first][i.second] = 'B';
                        for (auto &j : neighbors)
                        {
                            if (j.first >= 0 && j.first < board.size() && j.second >= 0 && j.second < board[0].size())
                            {
                                tmp.push_back(j);
                            }
                        }
                    }
                }
                else
                {
                    board[i.first][i.second] = '0' + m;
                }
            }
            qq = tmp;
        }
        return board;
    }
};
