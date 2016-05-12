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
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // write your code here
        return mergeHelper(lists, 0, lists.size() - 1);
    }
    
    ListNode* mergeHelper(vector<ListNode*>& lists, int start, int end) {
        if (start > end) return NULL;
        if (start == end) return lists[start];
        
        int mid = start + (end - start) / 2;
        ListNode* l1 = mergeHelper(lists, start, mid);
        ListNode* l2 = mergeHelper(lists, mid + 1, end);
        return mergeTwoLists(l1, l2);
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
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


