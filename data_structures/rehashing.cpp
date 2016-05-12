/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param hashTable: A list of The first node of linked list
     * @return: A list of The first node of linked list which have twice size
     */    
     
    void append(ListNode* head, ListNode* new_node) {
        if (!head) return;
        while (head->next) {
            head = head->next;
        }
        head->next = new_node;
    }
    
    int hashcode(int key, int capacity) {
        int code = key % capacity;
        return code >= 0 ? code : capacity + code;
    }
    
    void put(vector<ListNode*>& table, int key, int val) {
        ListNode* new_node = new ListNode(val);
        if (!table[key]) {
            table[key] = new_node;
        } else {
            append(table[key], new_node);
        }
    }
    
    vector<ListNode*> rehashing(vector<ListNode*> hashTable) {
        // write your code here
        
        int capacity = hashTable.size() * 2;
        vector<ListNode*> table(capacity, NULL);
        
        for (int i = 0; i < hashTable.size(); i++) {
            ListNode* curt = hashTable[i];
            while (curt) {
                int key = hashcode(curt->val, capacity);
                put(table, key, curt->val);
                curt = curt->next;
            }
        }
        return table;
    }
};

// attention: negative number hash code
// 如果是负数， 则 code = capacity + num % capacity

// scan the old table
//      recompute and put into new entry

// new table size = old_size * 2;

/*
* func(key, capacity)
*   return key % capacity
*/
