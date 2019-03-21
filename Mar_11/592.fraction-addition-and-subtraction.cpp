/*
 * @lc app=leetcode id=592 lang=cpp
 *
 * [592] Fraction Addition and Subtraction
 *
 * https://leetcode.com/problems/fraction-addition-and-subtraction/description/
 *
 * algorithms
 * Medium (46.58%)
 * Total Accepted:    12.2K
 * Total Submissions: 26.1K
 * Testcase Example:  '"-1/2+1/2"'
 *
 * Given a string representing an expression of fraction addition and
 * subtraction, you need to return the calculation result in string format. The
 * final result should be irreducible fraction. If your final result is an
 * integer, say 2, you need to change it to the format of fraction that has
 * denominator 1. So in this case, 2 should be converted to 2/1.
 *
 * Example 1:
 *
 * Input:"-1/2+1/2"
 * Output: "0/1"
 *
 *
 *
 * Example 2:
 *
 * Input:"-1/2+1/2+1/3"
 * Output: "1/3"
 *
 *
 *
 * Example 3:
 *
 * Input:"1/3-1/2"
 * Output: "-1/6"
 *
 *
 *
 * Example 4:
 *
 * Input:"5/3+1/3"
 * Output: "2/1"
 *
 *
 *
 * Note:
 *
 * The input string only contains '0' to '9', '/', '+' and '-'. So does the
 * output.
 * Each fraction (input and output) has format ±numerator/denominator. If the
 * first input fraction or the output is positive, then '+' will be omitted.
 * The input only contains valid irreducible fractions, where the numerator and
 * denominator of each fraction will always be in the range [1,10]. If the
 * denominator is 1, it means this fraction is actually an integer in a
 * fraction format defined above.
 * The number of given fractions will be in the range [1,10].
 * The numerator and denominator of the final result are guaranteed to be valid
 * and in the range of 32-bit int.
 *
 *
 */
// too slow
class Solution
{
  public:
    string fractionAddition(string expression)
    {
        int d = 1, n = 0;
        int pos = 0;
        while (pos < expression.size())
        {
            if ((pos == 0 && expression[pos] != '-') || expression[pos] == '+')
            {
                if (expression[pos] == '+')
                {
                    pos++;
                }
                auto v = parse(expression, pos);
                n = n * v.second + d * v.first;
                d = d * v.second;
                auto c = gcd(n, d);
                n /= c;
                d /= c;
            }
            else if (expression[pos] == '-')
            {
                pos++;
                auto v = parse(expression, pos);
                n = n * v.second - d * v.first;
                d = d * v.second;
                auto c = gcd(n, d);
                n /= c;
                d /= c;
            }
        }
        if (n == 0)
            return "0/1";
        return to_string(n) + "/" + to_string(d);
    }
    int gcd(int x, int y)
    {
        int z = y;
        while (x % y != 0)
        {
            z = x % y;
            x = y;
            y = z;
        }
        return abs(z);
    }
    pair<int, int> parse(string &s, int &pos)
    {
        int d = 0, n = 0;
        while (s[pos] >= '0' && s[pos] <= '9')
        {
            n *= 10;
            n += s[pos] - '0';
            pos++;
        }
        pos++;
        while (pos < s.size() && s[pos] >= '0' && s[pos] <= '9')
        {
            d *= 10;
            d += s[pos] - '0';
            pos++;
        }
        return make_pair(n, d);
    }
};
