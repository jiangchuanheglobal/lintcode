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
     * @param root, the root of binary tree.
     * @return true if it is a mirror of itself, or false.
     */
    bool isSymmetric(TreeNode* root) {
        // Write your code here
        if (!root) return true;
        return helper(root->left, root->right);
    }
    
    // 判断以a， b作为根节点的两棵树是否具有对称性
    bool helper(TreeNode* a, TreeNode* b) {
        if (!a && !b) return true;
        if (!a ^ !b) return false;
        return helper(a->left, b->right) &&
        helper(a->right, b->left) && a->val == b->val;
    }
