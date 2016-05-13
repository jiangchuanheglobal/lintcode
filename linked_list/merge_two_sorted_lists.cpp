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
     * @param ListNode l1 is the head of the linked list
     * @param ListNode l2 is the head of the linked list
     * @return: ListNode head of linked list
     */
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // write your code here
        ListNode dummy(0);
        ListNode* prev = &dummy;
        
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                prev->next = l1;
                l1 = l1->next;
                prev = prev->next;
            } else {
                prev->next = l2;
                l2 = l2->next;
                prev = prev->next;
            }
        }
        
        if (l1) {
            prev->next = l1;
        }
        if (l2) {
            prev->next = l2;
        }
        
        return dummy.next;
    }
