/*
 * @lc app=leetcode id=378 lang=cpp
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 */
class Solution
{
public:
    struct Node
    {
        Node(int ii, int jj, int vv) : i(ii), j(jj), val(vv) {}
        int i;
        int j;
        int val;
        bool operator<(const Node &n)
        {
            return val < n.val;
        }
        bool operator>(const Node &n)
        {
            return val > n.val;
        }
    };
    struct Comp
    {
        bool operator()(const Node &left, const Node &right)
        {
            return left.val > right.val;
        }
    };
    // bfs
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        priority_queue<Node, vector<Node>, Comp> pq;
        pq.push(Node(0, 0, matrix[0][0]));
        set<pair<int, int>> seen;
        while (pq.size())
        {
            auto n = pq.top();
            pq.pop();
            if (!seen.count(make_pair(n.i, n.j)))
            {
                k--;
                seen.insert(make_pair(n.i, n.j));
                if (k == 0)
                    return n.val;
                if (n.i < matrix.size() - 1)
                    pq.push(Node(n.i + 1, n.j, matrix[n.i + 1][n.j]));
                if (n.j < matrix.size() - 1)
                    pq.push(Node(n.i, n.j + 1, matrix[n.i][n.j + 1]));
            }
        }
        return 0;
    }
};
