/*
 * @lc app=leetcode id=187 lang=cpp
 *
 * [187] Repeated DNA Sequences
 *
 * https://leetcode.com/problems/repeated-dna-sequences/description/
 *
 * algorithms
 * Medium (35.29%)
 * Total Accepted:    117.6K
 * Total Submissions: 333.3K
 * Testcase Example:  '"AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"'
 *
 * All DNA is composed of a series of nucleotides abbreviated as A, C, G, and
 * T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to
 * identify repeated sequences within the DNA.
 * 
 * Write a function to find all the 10-letter-long sequences (substrings) that
 * occur more than once in a DNA molecule.
 * 
 * Example:
 * 
 * 
 * Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
 * 
 * Output: ["AAAAACCCCC", "CCCCCAAAAA"]
 * 
 * 
 */
class Solution
{
  public:
    vector<string> findRepeatedDnaSequences(string &s)
    {

        map<string, int> m;
        vector<string> res;
        if (s.size() < 10)
            return res;
        for (int i = 0; i <= s.size() - 10; i++)
        {
            string tmp = s.substr(i, 10);
            m[tmp]++;
        }
        for (auto &i : m)
        {
            if (i.second >= 2)
            {
                res.push_back(i.first);
            }
        }
        return res;
    }
};
