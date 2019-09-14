class MyLinkedList
{
    struct Node
    {
        Node(int v) : val(v) {}
        int val;
        Node *next{nullptr};
    };
    Node *mHead{nullptr};

public:
    /** Initialize your data structure here. */
    MyLinkedList()
    {
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index)
    {
        int res;
        auto it = mHead;
        while (it)
        {
            if (index == 0)
                return it->val;
            it = it->next;
            index--;
        }
        return -1;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val)
    {
        auto ptr = new Node(val);
        auto tmp = mHead;
        mHead = ptr;
        mHead->next = tmp;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val)
    {
        auto ptr = new Node(val);
        if (mHead == nullptr)
        {
            mHead = ptr;
        }
        else
        {
            auto it = mHead;
            while (it->next)
            {
                it = it->next;
            }
            it->next = ptr;
        }
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val)
    {
        if (index == 0)
        {
            addAtHead(val);
        }
        else
        {
            auto it = mHead;
            while (it)
            {
                if (index == 1)
                {
                    auto tmp = it->next;
                    it->next = new Node(val);
                    it->next->next = tmp;
                    break;
                }
                it = it->next;
                index--;
            }
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index)
    {
        if (index == 0)
        {
            if (mHead != nullptr)
            {
                auto tmp = mHead->next;
                delete mHead;
                mHead = tmp;
            }
        }
        else
        {
            auto it = mHead;
            while (it)
            {
                if (index == 1)
                {
                    Node *tmp;
                    if (it->next)
                    {
                        tmp = it->next->next;
                    }
                    delete it->next;
                    it->next = tmp;
                    break;
                }
                it = it->next;
                index--;
            }
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */