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
     * @param head: The first node of linked list.
     * @return: The node where the cycle begins. 
     *           if there is no cycle, return null
     */
    ListNode *detectCycle(ListNode *head) {
        // write your code here
        if (!head || !head->next) return NULL;
        
        ListNode* fast = head->next;
        ListNode* slow = head;
        while (fast != slow) {
            if (!fast->next || !fast->next->next) return NULL;
            fast = fast->next->next;
            slow = slow->next;
        }
        
        fast = head;
        while (fast != slow->next) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};


