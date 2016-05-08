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
    /**
     * @param root: The root of binary tree.
     * @return: Inorder in vector which contains node values.
     */
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> result;
        
        stack<TreeNode*> stk;
        
        while (root || !stk.empty()) {
            while (root) {
                stk.push(root);
                root = root->left;
            }
            
            root = stk.top();
            stk.pop();
            
            result.push_back(root->val);
            
            root = root->right;
        }
        
        return result;
    }
};
