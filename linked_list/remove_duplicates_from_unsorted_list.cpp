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
     * @return: head node
     */
     ListNode *removeDuplicates(ListNode *head) {
        // Write your code here
        if (!head || !head->next) return head;
        set<int> visit;
        
        ListNode* result = head;
        visit.insert(head->val);
        while (head->next) {
            if (visit.find(head->next->val) != visit.end()) {
                head->next = head->next->next;
            } else {
                head = head->next;
                visit.insert(head->val);
            }
        }
        
        return result;
    }
};

