/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution
{

    unordered_map<Node *, Node *> m;

public:
    // // BFS
    // Node *cloneGraph(Node *node)
    // {
    //     if (node == nullptr)
    //         return nullptr;

    //     auto root = new Node(node->val, {});
    //     m.emplace(node, root);

    //     stack<Node *> s;
    //     s.push(node);

    //     while (!s.empty())
    //     {
    //         auto top = s.top();
    //         s.pop();
    //         auto curr = m[top];
    //         for (auto i : top->neighbors)
    //         {
    //             auto it = m.find(i);
    //             if (it == m.end())
    //             {
    //                 auto cur_node = new Node(i->val, {});
    //                 s.push(i);
    //                 m.emplace(i, cur_node);
    //                 curr->neighbors.push_back(cur_node);
    //             }
    //             else
    //             {
    //                 curr->neighbors.push_back(it->second);
    //             }
    //         }
    //     }
    //     return root;
    // }
    // DFS
    Node *cloneGraph(Node *node)
    {
        if (node == nullptr)
            return nullptr;
        auto it = m.find(node);
        if (it == m.end())
        {
            auto root = new Node(node->val, {});
            m.emplace(node, root);
            for (auto i : node->neighbors)
            {
                root->neighbors.push_back(cloneGraph(i));
            }
            return root;
        }
        else
        {
            return it->second;
        }
    }
};
