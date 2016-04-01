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
     * @param x: an integer
     * @return: a ListNode 
     */
    ListNode *partition(ListNode *head, int x) {
        // write your code here
        if (!head) return head;
        
        ListNode dummy(0);
        ListNode dummy2(0);
        
        ListNode *pre = &dummy;
        ListNode *post = &dummy2;
        
        while (head) {
            ListNode* next = head->next;
            head->next = NULL;
            
            if (head->val < x) {
                pre->next = head;
                pre = pre->next;
            } else {
                post->next = head;
                post = post->next;
            }
            
            head = next;
        }
        
      
        pre->next = dummy2.next;
        return dummy.next;
    }
};

// 

