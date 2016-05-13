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
     * @oaram v1 an integer
     * @param v2 an integer
     * @return a new head of singly-linked list
     */
    ListNode* swapNodes(ListNode* head, int v1, int v2) {
        // Write your code here
        ListNode* n1 = findNode(head, v1);
        ListNode* n2 = findNode(head, v2);
        
        if (!n1 || !n2) return head;
        if (n1 == n2) return head;
        
        
        ListNode dummy(INT_MIN);
        dummy.next = head;
        
        ListNode* prev_n1 = findPrev(&dummy, v1);
        ListNode* prev_n2 = findPrev(&dummy, v2);
      
        ListNode* next_n1 = n1->next;
        ListNode* next_n2 = n2->next;
        
        if (prev_n2 == n1) {
            prev_n1->next = n2;
            n2->next = n1;
            n1->next = next_n2;
        } else if (prev_n1 == n2) {
            prev_n2->next = n1;
            n1->next = n2;
            n2->next = next_n1;;
        } else {
            prev_n1->next = n2;
            n2->next = next_n1;
            prev_n2->next = n1;
            n1->next = next_n2;
        }
        
    
        return dummy.next;
        
    }
    
    ListNode* findNode(ListNode* head, int val) {
        while (head && head->val != val) {
            head = head->next;
        }
        return head;
    }
    ListNode* findPrev(ListNode* head, int val) {
        if (!head) return NULL;
        if (head->val == val) return NULL;
        while (head->next->val != val) {
            head = head->next; 
        }
        return head;
    }
