/*
 * @lc app=leetcode id=415 lang=cpp
 *
 * [415] Add Strings
 *
 * https://leetcode.com/problems/add-strings/description/
 *
 * algorithms
 * Easy (43.21%)
 * Total Accepted:    86.8K
 * Total Submissions: 200.9K
 * Testcase Example:  '"0"\n"0"'
 *
 * Given two non-negative integers num1 and num2 represented as string, return
 * the sum of num1 and num2.
 *
 * Note:
 *
 * The length of both num1 and num2 is < 5100.
 * Both num1 and num2 contains only digits 0-9.
 * Both num1 and num2 does not contain any leading zero.
 * You must not use any built-in BigInteger library or convert the inputs to
 * integer directly.
 *
 *
 */
class Solution
{
  public:
    string addStrings(string num1, string num2)
    {
        string &l = num1.size() >= num2.size() ? num1 : num2;
        string &r = num1.size() < num2.size() ? num1 : num2;
        auto lit = l.rbegin();
        auto rit = r.rbegin();
        int nex = 0;
        while (lit != l.rend())
        {
            if (rit != r.rend())
            {
                int tmp = *lit - '0' + *rit - '0' + nex;
                *lit = tmp % 10+'0';
                nex = tmp / 10;
                lit++;
                rit++;
            }
            else
            {
                int tmp = *lit - '0' + nex;
                *lit = tmp % 10+'0';
                nex = tmp / 10;
                if(nex==0) break;
                lit++;
            }
        }
        if(nex==1) l.insert(0,"1");
        return l;
    }
};
