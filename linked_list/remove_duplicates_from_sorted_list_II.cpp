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
class Solution{
public:
    /**
     * @param head: The first node of linked list.
     * @return: head node
     */
    ListNode * deleteDuplicates(ListNode *head) {
        // write your code here
        if (!head) return head;
        
        map<int, int> times;
        ListNode dummy(0);
        ListNode *curt = head;
        while (curt) {
            if (times.find(curt->val) == times.end()) {
                times[curt->val] = 0;
            }
            times[curt->val] += 1; 
            curt = curt->next;
        }
        
        curt = head;
        ListNode *last = &dummy;
        while (curt) {
            if (times[curt->val] == 1) {
                last->next = curt;
                last = last->next;
            }
            curt = curt->next;
        }
        last->next = NULL;
        return dummy.next;
    }
};
