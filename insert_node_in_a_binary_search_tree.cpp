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
     * @param root: The root of the binary search tree.
     * @param node: insert this node into the binary search tree
     * @return: The root of the new binary search tree.
     */
    TreeNode* insertNode(TreeNode* root, TreeNode* node) {
        // write your code here
        if (!root) return node;
        TreeNode* parent;
        TreeNode* curt = root;
        while (curt) {
            parent = curt;
            if (node->val < curt->val) {
                curt = curt->left;
            } else {
                curt = curt->right;
            }
        }
        
        if (node->val < parent->val) {
            parent->left = node;
        } else {
            parent->right = node;
        }
        
        return root;
    }
};
