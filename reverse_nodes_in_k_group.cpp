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
     * @param k an integer
     * @return a ListNode
     */
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Write your code here
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        ListNode* tail = forwardKSteps(prev, k);
        
        while (tail != NULL) {
            
            ListNode* post = tail->next;
            tail->next = NULL; // break
            ListNode* new_tail = prev->next;
            prev->next = reverse(prev->next);
            new_tail->next = post;
            
            prev = forwardKSteps(prev, k);
            tail = forwardKSteps(new_tail, k);
        }
        
        return dummy.next;
    }
    
    ListNode* forwardKSteps(ListNode* node, int k) {
        while (k > 0 && node) {
            k -= 1;
            node = node->next;
        }
        return node;
    }

    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        
        while (head) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};
