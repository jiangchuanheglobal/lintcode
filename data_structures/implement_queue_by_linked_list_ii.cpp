class Dequeue {
public:    
    Dequeue() {
        // do initialize if necessary
        dummy_head = new DoublyListNode(0);
        dummy_tail = new DoublyListNode(0);
        dummy_head->next = dummy_tail;
        dummy_tail->prev = dummy_head;
    }

    void push_front(int item) {
        // Write your code here
        DoublyListNode* node = new DoublyListNode(item);
        dummy_head->next->prev = node;
        node->next = dummy_head->next;
        dummy_head->next = node;
        node->prev = dummy_head;
    }

    void push_back(int item) {
        // Write your code here
        DoublyListNode* node = new DoublyListNode(item);
        dummy_tail->prev->next = node;
        node->prev = dummy_tail->prev;
        dummy_tail->prev = node;
        node->next = dummy_tail;
    }

    int pop_front() {
        // Write your code here
        if (dummy_head->next == dummy_tail) return -1;
        
        DoublyListNode* front_node = dummy_head->next;
        
        dummy_head->next = front_node->next;
        front_node->next->prev = dummy_head;
        
        int ret = front_node->val;
        delete front_node;
        return ret;
    }

    int pop_back() {
        // Write your code here
        if (dummy_head->next == dummy_tail) return -1;
        
        DoublyListNode* back_node = dummy_tail->prev;
        dummy_tail->prev = back_node->prev;
        back_node->prev->next = dummy_tail;
        
        int ret = back_node->val;
        delete back_node;
        return ret;
    }
    
    DoublyListNode* dummy_head;
    DoublyListNode* dummy_tail;
};
	
