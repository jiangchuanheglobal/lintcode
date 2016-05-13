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
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: a tree node
     */
    ListNode* findKthListNode(ListNode* head, int k) {
        while (k > 0 && head) {
            k -= 1;
            head = head->next;
        }
        return head;
    }
    int length(ListNode* head) {
        int len = 0;
        while (head) {
            head = head->next;
            len += 1;
        }
        return len;
    }
    TreeNode *sortedListToBST(ListNode *head) {
        // write your code here
        return helper(head, 0, length(head) - 1);
    }
    
    TreeNode* helper(ListNode* head, int left, int right) {
        if (left > right) return NULL;
        
        int mid = left + (right - left) / 2;
        ListNode* mid_node = findKthListNode(head, mid);
        TreeNode* root = new TreeNode(mid_node->val);
        
        root->left = helper(head, left, mid - 1);
        root->right = helper(mid_node->next, 0, right - mid - 1);
        
        return root;
    }
    
};


