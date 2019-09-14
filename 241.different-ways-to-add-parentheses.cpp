/*
 * @lc app=leetcode id=241 lang=cpp
 *
 * [241] Different Ways to Add Parentheses
 */
class Solution
{
public:
    vector<int> diffWaysToCompute(const string &input)
    {
        vector<int> res;
        auto cutPoint = input.find_first_of("+-*", 0); // find the first operator
        if (cutPoint == string::npos)
            return vector<int>(1, stoi(input)); // if only number, just return the value
        do
        {
            for (auto it1 : diffWaysToCompute(input.substr(0, cutPoint)))      // calculate the first substring
                for (auto it2 : diffWaysToCompute(input.substr(cutPoint + 1))) // calculate the second substring
                    if (input[cutPoint] == '+')
                        res.push_back(it1 + it2); // combine
                    else if (input[cutPoint] == '-')
                        res.push_back(it1 - it2);
                    else if (input[cutPoint] == '*')
                        res.push_back(it1 * it2);
        } while ((cutPoint = input.find_first_of("+-*", cutPoint + 1)) != string::npos); // move to next operator
        return res;
    }
};
