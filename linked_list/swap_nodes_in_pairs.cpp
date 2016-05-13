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
     * @return a ListNode
     */
    ListNode* swapPairs(ListNode* head) {
        // Write your code here
        ListNode dummy1(0);
        ListNode dummy2(0);
        ListNode dummy3(0);
        ListNode* first = &dummy1;
        ListNode* second = &dummy2;
        ListNode* prev = &dummy3;
        bool flag = true;
        
        while (head) {
            if (flag) {
                first->next = head;
                first = first->next;
            } else {
                second->next = head;
                second = second->next;
            }
            head = head->next;
            flag = !flag;
        }
        
        first->next = NULL;
        second->next = NULL;
        
        first = dummy2.next;
        second = dummy1.next;
        flag = true;
        while (first && second) {
            if (flag) {
                prev->next = first;
                first = first->next;
            } else {
                prev->next = second;
                second = second->next;
            }
            prev = prev->next;
            flag = !flag;
        }
        if (first) {
            prev->next = first;
        } else {
            prev->next = second;
        }
        
        return dummy3.next;
    }
