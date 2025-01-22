class LRUCache {
    struct Node {
        int key, val;
        Node* next;
        Node* prev;

        Node(int k, int v) : key(k), val(v), next(nullptr), prev(nullptr) {}
    };

    unordered_map<int, Node*> mpp; // Map to store key to node mapping
    int cap;                       // Capacity of the cache
    Node* head;                    // Dummy head node
    Node* tail;                    // Dummy tail node

    // Insert a node right after the head
    void insertAfter(Node* node) {
        Node* curr = head->next;
        head->next = node;
        node->next = curr;
        node->prev = head;
        curr->prev = node;
    }

    // Delete a node from its current position
    void deletion(Node* node) {
        Node* prevNode = node->prev;
        Node* afterNode = node->next;
        prevNode->next = afterNode;
        afterNode->prev = prevNode;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        mpp.clear();
        head = new Node(-1, -1); // Dummy head node
        tail = new Node(-1, -1); // Dummy tail node
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mpp.count(key) == 0) return -1; // Key not found
        Node* node = mpp[key];
        deletion(node);        // Move the accessed node to the front
        insertAfter(node);
        return node->val;
    }

    void put(int key, int value) {
        if (mpp.count(key)) {
            // Key already exists, update its value and move it to the front
            Node* node = mpp[key];
            node->val = value;
            deletion(node);
            insertAfter(node);
        } else {
            if (mpp.size() == cap) {
                // Cache is full, remove the least recently used node
                Node* node = tail->prev;
                mpp.erase(node->key); // Remove from map
                deletion(node);       // Remove from the linked list
                delete node;          // Free memory
            }
            // Add the new key-value pair
            Node* node = new Node(key, value);
            mpp[key] = node;
            insertAfter(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
