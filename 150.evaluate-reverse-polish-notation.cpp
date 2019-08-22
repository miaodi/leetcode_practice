/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */
class Solution
{

public:
    int evalRPN(vector<string> &tokens)
    {
        if (tokens.empty())
            return 0;
        unordered_map<char, function<int(int, int)>> m;
        m['+'] = [](int a, int b) { return a + b; };
        m['-'] = [](int a, int b) { return a - b; };
        m['*'] = [](int a, int b) { return a * b; };
        m['/'] = [](int a, int b) { return a / b; };
        stack<string> s;
        for (const auto &i : tokens)
        {
            if (i == "+" || i == "-" || i == "*" || i == "/")
            {
                int b = stoi(s.top());
                s.pop();
                int a = stoi(s.top());
                s.pop();
                int tmp = m[i[0]](a, b);
                s.push(std::to_string(tmp));
            }
            else
            {
                s.push(i);
            }
        }
        return stoi(s.top());
    }
};
