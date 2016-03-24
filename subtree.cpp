/**
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
     * @param T1, T2: The roots of binary tree.
     * @return: True if T2 is a subtree of T1, or false.
     */
    bool isSubtree(TreeNode *T1, TreeNode *T2) {
        // write your code here
        if (T1 == NULL && T2 == NULL) {
            return true;
        } else if (T1 != NULL && T2 == NULL) {
            return true;
        } else if (T1 == NULL && T2 != NULL) {
            return false;
        } else {
            stack<TreeNode*> stk;
            stk.push(T1);
            while (!stk.empty()) {
                TreeNode* n = stk.top();
                stk.pop();
                
                if (sameTree(n, T2)) {
                    return true;
                }
                
                if (n->right) {
                    stk.push(n->right);
                }
                if (n->left) {
                    stk.push(n->left);
                }
            }
            return false;
        }
    }
    
    bool sameTree(TreeNode* n1, TreeNode* n2) {
        if (n1 == NULL && n2 == NULL) {
            return true;
        } else if (n1 != NULL && n2 != NULL) {
            return n1->val == n2->val && 
                sameTree(n1->left, n2->left) &&
                sameTree(n1->right, n2->right);
        } else {
            return false;
        }
    }
};
