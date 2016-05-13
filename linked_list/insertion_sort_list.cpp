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
     * @return: The head of linked list.
     */
    ListNode *insertionSortList(ListNode *head) {
        // write your code here
        ListNode dummy(0);
        ListNode* prev;
        
        while (head) {
            ListNode* tmp = head;
            head = head->next;
            
            prev = &dummy;
            while (prev->next && tmp->val > prev->next->val) {
                prev = prev->next;
            }
            
            tmp->next = prev->next;
            prev->next = tmp;
        }
        return dummy.next;
    }
