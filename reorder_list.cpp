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
     * @return: void
     */
     
    ListNode* findMedian(ListNode *head) {
       ListNode* fast = head;
       ListNode* slow = head;
       while (fast && fast->next && fast->next->next) {
           fast = fast->next->next;
           slow = slow->next;
       }
        return slow;
    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        while (head) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    
    void merge(ListNode* head, ListNode* second) {
        ListNode* prev = head;
        ListNode* first = head->next;
        bool gofirst = false;
        while (first && second) {
            if (gofirst) {
                prev->next = first;
                first = first->next;
                
            } else {
                prev->next = second;
                second = second->next;
            }
            gofirst = !gofirst;
            prev = prev->next;
        }
        
        if (first) {
            prev->next = first;
        } else {
            prev->next = second;
        }
    }
    void reorderList(ListNode *head) {
        // write your code here
        if (!head || !head->next) return;
        
        ListNode* mid = findMedian(head);
        
        ListNode* second = mid->next;
        mid->next = NULL;
        
        second = reverseList(second);
        merge(head, second);
    }
};

// N
// 1

// 1 -> 2

// 1 2  3
// 4 -> 5
// 1 -> 2 -> 3
// 

// 
