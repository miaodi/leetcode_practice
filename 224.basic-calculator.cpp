/*
 * @lc app=leetcode id=224 lang=cpp
 *
 * [224] Basic Calculator
 */
class Solution
{

    int precedence(const char &c)
    {
        if (c == '+' || c == '-')
            return 1;
        else if (c == '*' || c == '/')
            return 2;

        return 0;
    }
    bool inline is_op(const char &c)
    {
        return c == '+' || c == '-' || c == '*' || c == '/';
    }
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

public:
    int calculate(const string s)
    {
        vector<string> post;
        stack<string> sta;
        for (int i = 0; i < s.size();)
        {
            if (s[i] == ' ')
            {
                i++;
                continue;
            }
            if (is_op(s[i]))
            {
                while (!sta.empty() && is_op(sta.top()[0]) && precedence(sta.top()[0]) >= precedence(s[i]))
                {
                    post.push_back(sta.top());
                    sta.pop();
                }
                sta.push(string(1, s[i]));
                i++;
            }
            else if (s[i] == '(')
            {
                sta.push("(");
                i++;
            }
            else if (s[i] == ')')
            {
                while (sta.top()[0] != '(')
                {
                    post.push_back(sta.top());
                    sta.pop();
                }
                sta.pop();
                i++;
            }
            else
            {
                int j = 0;
                while (isdigit(s[i + j]) && i + j < s.size())
                {
                    j++;
                }
                post.push_back(s.substr(i, j));
                i += j;
            }
        }
        while (!sta.empty())
        {
            post.push_back(sta.top());
            sta.pop();
        }
        return evalRPN(post);
    }
};
