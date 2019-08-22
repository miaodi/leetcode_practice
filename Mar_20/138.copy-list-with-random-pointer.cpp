/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 *
 * https://leetcode.com/problems/copy-list-with-random-pointer/description/
 *
 * algorithms
 * Medium (26.05%)
 * Total Accepted:    228.8K
 * Total Submissions: 878.3K
 * Testcase Example:
 * '{"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}'
 *
 * A linked list is given such that each node contains an additional random
 * pointer which could point to any node in the list or null.
 *
 * Return a deep copy of the list.
 *
 *
 *
 * Example 1:
 *
 *
 *
 *
 * Input:
 *
 * {"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}
 *
 * Explanation:
 * Node 1's value is 1, both of its next and random pointer points to Node 2.
 * Node 2's value is 2, its next pointer points to null and its random pointer
 * points to itself.
 *
 *
 *
 *
 * Note:
 *
 *
 * You must return the copy of the given head as a reference to the cloned
 * list.
 *
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution
{
  public:
    Node *copyRandomList(Node *head)
    {
        if (head == nullptr)
            return nullptr;
        unordered_map<Node *, Node *> m;
        auto res = new Node(head->val, nullptr, nullptr);
        auto it_res = res;
        auto it = head;
        m[head] = res;
        while (it != nullptr)
        {
            if (it->random != nullptr)
            {
                auto ran = m.find(it->random);
                if (ran == m.end())
                {
                    auto tmp = new Node(it->random->val, nullptr, nullptr);
                    tmp->val = it->random->val;
                    it_res->random = tmp;
                    m[it->random] = tmp;
                }
                else
                {
                    it_res->random = ran->second;
                }
            }
            if (it->next != nullptr)
            {
                auto nex = m.find(it->next);
                if (nex == m.end())
                {
                    auto tmp = new Node(it->next->val, nullptr, nullptr);
                    tmp->val = it->next->val;
                    it_res->next = tmp;
                    m[it->next] = tmp;
                }
                else
                {
                    it_res->next = nex->second;
                }
            }
            it_res = it_res->next;
            it = it->next;
        }
        return res;
    }
};
