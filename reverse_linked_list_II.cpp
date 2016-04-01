/**
 * Definition of singly-linked-list:
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The head of linked list.
     * @param m: The start position need to reverse.
     * @param n: The end position need to reverse.
     * @return: The new head of partial reversed linked list.
     */
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // write your code here
        ListNode dummy(0);
        ListNode* prev = &dummy;
        dummy.next = head;
        
        int num = m - 1;
        while (num > 0) {
            num -= 1;
            prev = prev->next;
        }
        
        // rotate the body
        num = n - m + 1;
        ListNode* front = NULL;
        ListNode* next = NULL;
        ListNode* curt = prev->next;
        while (num > 0) {
            next = curt->next;
            curt->next = front;
            front = curt;
            curt = next;
            num -= 1;
        }
        
        prev->next->next = curt;
        prev->next = front;
        
        return dummy.next;
    }
};
