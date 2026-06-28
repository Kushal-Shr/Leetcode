class LRUCache {
public:

    class Node 
    {
        public: 
        int key, val;
        Node *prev;
        Node* next;

        Node (int k, int v)
        {
            key = k;
            val = v;
            prev = next = nullptr;
        }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    unordered_map<int, Node*> m;

    void addNode(Node* newNode)
    {
        Node* oldNext = head->next;
        head->next = newNode;
        oldNext->prev = newNode;
        newNode->next = oldNext;
        newNode->prev = head;
    }

    void delNode(Node* oldNode)
    {
        Node* oldPrev = oldNode->prev;
        Node* oldNext = oldNode->next;
        oldPrev->next = oldNext;
        oldNext->prev = oldPrev;
    }

    int limit = 0;

    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (m.find(key) != m.end())
        {
            Node* oldNode = m[key];
            delNode(oldNode);
            addNode(oldNode);

            return oldNode->val;
        }

        else
        {
            return -1;
        }
    }

    void put(int key, int value) {
        if (m.find(key) != m.end())
        {
            Node* oldNode = m[key];

            oldNode->val = value;
            delNode(oldNode);
            addNode(oldNode);
            
            return ;
        }

        if (m.size() == limit)
        {
            Node* lru = tail->prev;
            delNode(lru);
            m.erase(lru->key);

            delete lru;
        }

        Node* newNode = new Node(key, value);
        addNode(newNode);
        m[key] = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */