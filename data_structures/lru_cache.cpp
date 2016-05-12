class Node {
  public:
  Node(int key, int val) {
      this->key = key;
      this->val = val;
      prev = NULL;
      next = NULL;
  }
  int key;
  int val;
  Node* prev;
  Node* next;
};

class LRUCache{
public:
    // @param capacity, an integer
    LRUCache(int capacity):dummyHead(0,0), dummyTail(0,0) {
        // write your code here
        this->capacity = capacity;
        dummyHead.next = &dummyTail;
        dummyTail.prev = &dummyHead;
    }

    // @return an integer
    int get(int key) {
        if (mapping.find(key) == mapping.end()) {
            return -1;
        }
        
        Node* node = mapping[key];
        
        // extract this node
        node->prev->next = node->next;
        node->next->prev = node->prev;
        
        // move to tail
        moveToTail(node);
        return node->val;
    }

    // @param key, an integer
    // @param value, an integer
    // @return nothing
    void set(int key, int value) {
        // write your code here
        if (get(key) != -1) {
            mapping[key]->val = value;
            return;
        }

        if (mapping.size() == capacity) { // capacity >= 1
            mapping.erase(dummyHead.next->key);
            deleteHead();
        }

        Node* node = new Node(key, value);
        mapping[key] = node;
        moveToTail(node);
    }

private:
    void moveToTail(Node* node) {
        dummyTail.prev->next = node;
        node->prev = dummyTail.prev;
        
        node->next = &dummyTail;
        dummyTail.prev = node;
    }
    void deleteHead() {
        Node* head = dummyHead.next;
        dummyHead.next = head->next;
        head->next->prev = &dummyHead;
        delete head;
    }
    Node dummyHead;
    Node dummyTail;
    int capacity;
    map<int, Node*> mapping;
};

// doubly-ll & hash

// newest tail, oldest head

// dummy, capacity, tail_ptr

// get: hash, take and append
