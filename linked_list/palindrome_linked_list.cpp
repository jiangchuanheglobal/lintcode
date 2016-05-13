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
     * @return a boolean
     */
    bool isPalindrome(ListNode* head) {
        // Write your code here
        if (!head || !head->next) return true;
        
        ListNode* middle = findMiddle(head);
        
        ListNode* next = middle->next;
        middle->next = NULL;
        
        ListNode* l2 = reverse(next);
        ListNode* l1 = head;
        
        ListNode* tmp = l2;
        while (l2 && l2->val == l1->val) {
            l2 = l2->next;
            l1 = l1->next;
        }
        
        next = reverse(tmp);
        middle->next = next;
        
        if (l2) {
            return false;
        } else {
            return true;
        }
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
    
    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
