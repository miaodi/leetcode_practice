/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 *
 * https://leetcode.com/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (29.92%)
 * Total Accepted:    183.2K
 * Total Submissions: 612.2K
 * Testcase Example:  '"2"\n"3"'
 *
 * Given two non-negative integers num1 and num2 represented as strings, return
 * the product of num1 and num2, also represented as a string.
 * 
 * Example 1:
 * 
 * 
 * Input: num1 = "2", num2 = "3"
 * Output: "6"
 * 
 * Example 2:
 * 
 * 
 * Input: num1 = "123", num2 = "456"
 * Output: "56088"
 * 
 * 
 * Note:
 * 
 * 
 * The length of both num1 and num2 is < 110.
 * Both num1 and num2 contain only digits 0-9.
 * Both num1 and num2 do not contain any leading zero, except the number 0
 * itself.
 * You must not use any built-in BigInteger library or convert the inputs to
 * integer directly.
 * 
 * 
 */
// pretty slow need to review better solutions.
class Solution
{
  public:
    string multiply(string num1, string num2)
    {
        if(num1=="0"||num2=="0") return "0";
        string res = "0";
        int digit = 0;
        for (auto it = num2.rbegin(); it != num2.rend(); it++)
        {
            auto m = multiply_int(num1, *it - '0');
            m += string(digit, '0');
            sum(res, m);
            digit++;
        }
        return res;
    }
    string multiply_int(string &num1, int num)
    {
        string res(num1.size() + 1, '0');
        int digit = res.size() - 1;
        for (auto it = num1.rbegin(); it != num1.rend(); it++)
        {

            int v = *it - '0';
            int mul = v * num + (int)(res[digit] - '0');
            int next = mul / 10;
            int curr = mul % 10;
            res[digit] = curr + '0';
            res[digit - 1] = next + '0';
            digit--;
        }
        if (res[0] == '0')
            res.erase(res.begin());
        return res;
    }
    void sum(string &num1, string &num2)
    {
        if (num1.size() < num2.size())
        {
            swap(num1, num2);
        }
        int digit = num1.size() - 1;
        int next = 0;

        for (auto it = num2.rbegin(); it != num2.rend(); it++)
        {
            int sum = (int)(*it - '0') + next + (int)(num1[digit] - '0');
            next = sum / 10;
            num1[digit] = sum % 10 + '0';
            digit--;
        }
        for (; digit >= 0; digit--)
        {
            int sum = next + (int)(num1[digit] - '0');
            next = sum / 10;
            num1[digit] = sum % 10 + '0';
        }
        if (next != 0)
        {
            num1.insert(num1.begin(), '0' + next);
        }
    }
};
