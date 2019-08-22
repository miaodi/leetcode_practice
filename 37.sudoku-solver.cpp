/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 *
 * https://leetcode.com/problems/sudoku-solver/description/
 *
 * algorithms
 * Hard (36.25%)
 * Total Accepted:    123.9K
 * Total Submissions: 341.3K
 * Testcase Example:  '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 * 
 * A sudoku solution must satisfy all of the following rules:
 * 
 * 
 * Each of the digits 1-9 must occur exactly once in each row.
 * Each of the digits 1-9 must occur exactly once in each column.
 * Each of the the digits 1-9 must occur exactly once in each of the 9 3x3
 * sub-boxes of the grid.
 * 
 * 
 * Empty cells are indicated by the character '.'.
 * 
 * 
 * A sudoku puzzle...
 * 
 * 
 * ...and its solution numbers marked in red.
 * 
 * Note:
 * 
 * 
 * The given board contain only digits 1-9 and the character '.'.
 * You may assume that the given Sudoku puzzle will have a single unique
 * solution.
 * The given board size is always 9x9.
 * 
 * 
 */
class Solution
{
  public:
    void solveSudoku(vector<vector<char>> &board)
    {
        helper(board, 0);
    }
    bool checker(const vector<vector<char>> &board, int i, int j, char c)
    {
        int row = i / 3;
        int col = j / 3;
        for (int k = 0; k < 9; k++)
        {
            if (board[k][j] == c)
                return false;
            if (board[i][k] == c)
                return false;

            // block check
            if (board[k / 3 + row * 3][k % 3 + col * 3] == c)
                return false;
        }
        return true;
    }
    bool helper(vector<vector<char>> &board, int pos)
    {

        while (pos < 81 && board[pos / 9][pos % 9] != '.')
        {
            pos++;
        }
        if (pos == 81)
            return true;
        for (int i = 1; i <= 9; i++)
        {
            if (checker(board, pos / 9, pos % 9, '0' + i))
            {
                board[pos / 9][pos % 9] = '0' + i;
                if (helper(board, pos + 1))
                    return true;
                board[pos / 9][pos % 9] = '.';
            }
        }
        return false;
    }
};
