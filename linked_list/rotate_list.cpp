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
     * @param head: the list
     * @param k: rotate to the right k places
     * @return: the list after rotation
     */
    int length(ListNode* head) {
        int len = 0;
        while (head) {
            len += 1;
            head = head->next;
        }
        return len;
    }
    
    ListNode* findKthNode(ListNode* head, int k) {
        while (k > 0 && head) {
            head = head->next;
            k -= 1;
        }
        return head;
    }
    ListNode *rotateRight(ListNode *head, int k) {
        // write your code here
        if (!head) return NULL;
        int len = length(head);
        
        k = k % len;
        
        ListNode dummy(0);
        dummy.next = head;
        head = &dummy;
        
        ListNode* tail = head;
        head = findKthNode(head, k);

        while (head->next) {
            tail = tail->next;
            head = head->next;
        }

        head->next = dummy.next;
        dummy.next = tail->next; 
        tail->next = NULL;
        return dummy.next;
    }
