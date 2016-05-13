/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head a ListNode
     * @param val an integer
     * @return a ListNode
     */
    ListNode *removeElements(ListNode *head, int val) {
        // Write your code here
        ListNode dummy(0);
        ListNode* prev = &dummy;
        
        while(head) {
            if (head->val != val) {
                prev->next = head;
                prev = prev->next;
            }
            head = head->next;
        }
        prev->next = NULL;
        return dummy.next;
    }
};
