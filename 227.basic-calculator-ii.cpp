/*
 * @lc app=leetcode id=227 lang=cpp
 *
 * [227] Basic Calculator II
 *
 * https://leetcode.com/problems/basic-calculator-ii/description/
 *
 * algorithms
 * Medium (33.06%)
 * Total Accepted:    104.1K
 * Total Submissions: 314.8K
 * Testcase Example:  '"3+2*2"'
 *
 * Implement a basic calculator to evaluate a simple expression string.
 * 
 * The expression string contains only non-negative integers, +, -, *, /
 * operators and empty spaces  . The integer division should truncate toward
 * zero.
 * 
 * Example 1:
 * 
 * 
 * Input: "3+2*2"
 * Output: 7
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: " 3/2 "
 * Output: 1
 * 
 * Example 3:
 * 
 * 
 * Input: " 3+5 / 2 "
 * Output: 5
 * 
 * 
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
        for (auto it = s.begin(); it != s.end();)
        {
            if (*it == ' ')
            {
                it = s.erase(it);
            }
            else
            {
                it++;
            }
        }
        while (true)
        {
            bool checker = false;
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] == '*' || s[i] == '/')
                {
                    checker = true;
                    int l = i - 1, r = i + 1;
                    while (l >= 0 && s[l] >= '0' && s[l] <= '9')
                    {
                        l--;
                    }
                    while (r < s.size() && s[r] >= '0' && s[r] <= '9')
                    {
                        r++;
                    }
                    int tmp;
                    if (s[i] == '*')
                    {
                        tmp = stoi(s.substr(l + 1, i - l - 1)) * stoi(s.substr(i + 1, r - i - 1));
                    }
                    else
                    {
                        tmp = stoi(s.substr(l + 1, i - l - 1)) / stoi(s.substr(i + 1, r - i - 1));
                    }
                    s = s.substr(0, l + 1) + to_string(tmp) + s.substr(r, s.size() - r);
                    break;
                }
            }
            if (checker == false)
                break;
        }
        int pos = 0;
        while (pos < s.size() && (s[pos] != '+' && s[pos] != '-'))
        {
            pos++;
        }
        long val = stoi(s.substr(0, pos));
        for (; pos < s.size();)
        {
            int tmp = pos + 1;
            while (tmp < s.size() && (s[tmp] != '+' && s[tmp] != '-'))
            {
                tmp++;
            }
            if (s[pos] == '+')
            {
                val += stoi(s.substr(pos + 1, tmp - pos - 1));
            }
            else
            {
                val -= stoi(s.substr(pos + 1, tmp - pos - 1));
            }
            pos = tmp;
        }
        return val;
    }
};
