/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        // write your code here
        target = NULL;
        preorder(root, p);
        return target;
    }
    
    void preorder(TreeNode* root, TreeNode* p) {
        if (!root) return;
        
        if (root->val > p->val) {
            if (!target) target = root;
            
            target = root->val < target->val ? root : target;
        }
        preorder(root->left, p);
        preorder(root->right, p);
    }
    TreeNode* target;
};
