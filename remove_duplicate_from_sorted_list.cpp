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
    ListNode *deleteDuplicates(ListNode *head) {
        // write your code here
        if (!head || !head->next) return head;
        
        ListNode* prev = head;
        while (prev->next) {
            if (prev->val == prev->next->val) {
                prev->next = prev->next->next;
            } else {
                prev = prev->next;
            }
        }
        return head;
    }
};
