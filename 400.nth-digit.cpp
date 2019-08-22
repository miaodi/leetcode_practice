/*
 * @lc app=leetcode id=400 lang=cpp
 *
 * [400] Nth Digit
 */
class Solution
{
public:
    int findNthDigit(int n)
    {
        long int digit = 1;
        while (9 * pow(10, digit - 1) * digit < n)
        {
            n -= 9 * pow(10, digit - 1) * digit;
            digit++;
        }
        int nn = (n - 1) / digit + 1;
        cout << nn << endl;
        if (digit > 1)
        {
            nn += pow(10, digit - 1) - 1;
        }
        int dd = n % digit;
        cout << nn << endl;
        for (int i = 0; i < dd; i++)
        {
            nn /= 10;
        }
        return nn % 10;
    }
};
