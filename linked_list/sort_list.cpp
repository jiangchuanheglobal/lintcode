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
     * @return: You should return the head of the sorted linked list,
                    using constant space complexity.
     */
     
    
    ListNode *sortList(ListNode *head) {
        // write your code here
        if (!head || !head->next) return head;
        
        ListNode* mid = findMedian(head);
        
        ListNode* l2 = mid->next;
        mid->next = NULL;
        ListNode* l1 = head;
        
        
        l1 = sortList(l1);
        l2 = sortList(l2);
        
        return mergeTwoSortedList(l1, l2);
    }
    
    ListNode* findMedian(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    
    ListNode* mergeTwoSortedList(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* prev = &dummy;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                prev->next = l1;
                l1 = l1->next;
            } else {
                prev->next = l2;
                l2 = l2->next;
            }
            prev = prev->next;
        }
        
        if (l1) {
            prev->next = l1;
        } else {
            prev->next = l2;
        }
        return dummy.next;
    }
};


