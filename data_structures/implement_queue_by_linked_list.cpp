class Queue {
public:
    Queue() {
        // do initialize if necessary
        dummy_head = new ListNode(0);
        tail = dummy_head;
    }

    void enqueue(int item) {
        // Write your code here
        tail->next = new ListNode(item);
        tail = tail->next;
    }

    int dequeue() {
        // Write your code here
        if (!dummy_head->next) return -1;
        
        ListNode* head= dummy_head->next;
        dummy_head->next = dummy_head->next->next;
        
        if (!dummy_head->next) {
            tail = dummy_head;
        }
        
        return head->val;
    }
    
    ListNode* dummy_head;
    ListNode* tail;
};
	
