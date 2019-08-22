/*
 * @lc app=leetcode id=224 lang=cpp
 *
 * [224] Basic Calculator
 *
 * https://leetcode.com/problems/basic-calculator/description/
 *
 * algorithms
 * Hard (31.80%)
 * Total Accepted:    96.7K
 * Total Submissions: 303.9K
 * Testcase Example:  '"1 + 1"'
 *
 * Implement a basic calculator to evaluate a simple expression string.
 *
 * The expression string may contain open ( and closing parentheses ), the plus
 * + or minus sign -, non-negative integers and empty spaces  .
 *
 * Example 1:
 *
 *
 * Input: "1 + 1"
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: " 2-1 + 2 "
 * Output: 3
 *
 * Example 3:
 *
 *
 * Input: "(1+(4+5+2)-3)+(6+8)"
 * Output: 23
 * Note:
 *
 *
 * You may assume that the given expression is always valid.
 * Do not use the eval built-in library function.
 *
 *
 */
class Solution
{
  public:
    int calculate(string s)
    {
        int res = 0;
        if (s.size() == 0)
            return res;
        auto it = s.begin();
        stack<int> ss;
        stack<int> sign;
        while (it != s.end())
        {
            if (*it == '(')
            {
                if (it == s.begin() || (*(it - 1) != '-' && *(it - 1) != '+'))
                {
                    sign.push(1);
                }
                ss.push(res);
                res = 0;
                it++;
            }
            else if (*it == ')')
            {
                res *= sign.top();
                sign.pop();
                res += ss.top();
                ss.pop();
                it++;
            }
            else if (*it == '-')
            {
                sign.push(-1);
                it++;
            }
            else if (*it == '+')
            {
                sign.push(1);
                it++;
            }
            else if (*it == ' ')
            {
                it++;
            }
            else
            {
                if (it == s.begin() || (*(it - 1) != '-' && *(it - 1) != '+'))
                {
                    sign.push(1);
                }
                auto tmp = stringPaser(it, s.end());
                tmp *= sign.top();
                sign.pop();
                res += tmp;
            }
        }
        return res;
    }
    int stringPaser(string::iterator &sit, string::iterator end)
    {
        int res = 0;
        while (*sit != '+' && *sit != ' ' && *sit != '-' && *sit != '(' && *sit != ')' &&
               sit != end)
        {
            res *= 10;
            res += *sit - '0';
            sit++;
        }
        return res;
    }
};
