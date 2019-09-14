/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 */
class Solution
{
public:
    int countPrimes(int n)
    {
        vector<bool> primes(n, true);
        for (int i = 2; i < n; i++)
        {
            if (primes[i])
            {
                for (int j = i * 2; j < n; j += i)
                {
                    primes[j] = false;
                }
            }
        }
        int count = 0;
        for (int i = 2; i < n; i++)
        {
            if (primes[i])
                count++;
        }
        return count;
    }
};
