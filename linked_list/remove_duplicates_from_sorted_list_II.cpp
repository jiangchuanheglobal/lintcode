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
class Solution{
public:
    /**
     * @param head: The first node of linked list.
     * @return: head node
     */
    ListNode * deleteDuplicates(ListNode *head) {
        // write your code here
        ListNode dummy(INT_MIN);
        ListNode* prev = &dummy;
        ListNode* node = &dummy;
        ListNode* curt = head;
        
        while (curt) {
            if (curt->next) {
                if (prev->val != curt->val && curt->val != curt->next->val) {
                    node->next = curt;
                    node = node->next;
                }
            } else {
                if (prev->val != curt->val) {
                    node->next = curt;
                    node = node->next;
                }
            }
            curt = curt->next;
            prev = prev->next;
        }
        node->next = NULL;
        return dummy.next;
    }
};
