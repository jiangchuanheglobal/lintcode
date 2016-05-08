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
     * @param root the root of binary tree.
     * @return an integer
     */
    int maxPathSum2(TreeNode *root) {
        // Write your code here
        if (!root) return 0;
        int path = root->val;
        int sum = INT_MIN;
        DFS(root, path, sum);
        return sum;
    }
    
    void DFS(TreeNode* root, int& path, int& sum) {
        sum = ::max(sum, path);
        
        if (root->left) {
            path += root->left->val;
            DFS(root->left, path, sum);
            path -= root->left->val;
        }
        if (root->right) {
            path += root->right->val;
            DFS(root->right, path, sum);
            path -= root->right->val;
        }
    }
};
