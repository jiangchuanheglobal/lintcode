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
     * @param l1: the first list
     * @param l2: the second list
     * @return: the sum list of l1 and l2 
     */
    ListNode *addLists2(ListNode *l1, ListNode *l2) {
        // write your code here
        l1 = reverse(l1);
        l2 = reverse(l2);
        return reverse(addLists(l1, l2));
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
    ListNode *addLists(ListNode *l1, ListNode *l2) {
        // write your code here
        ListNode dummy(0);
        ListNode* prev = &dummy;
        int carry = 0;
        while (l1 || l2) {
            int sum = 0;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            
            sum += carry;
            ListNode* node = new ListNode(sum%10);
            prev->next = node;
            prev = prev->next;
            
            carry = sum/10;
        }
        
        // 易错点
        if (carry) {
            ListNode* node = new ListNode(carry);
            prev->next = node;
        }
        return dummy.next;
    }
