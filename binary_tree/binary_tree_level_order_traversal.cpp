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
     * @return: Level order a list of lists of integer
     */
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        // write your code here
        vector<vector<int>> result;
        if (!root) return result;
        
        queue<TreeNode*> que;
        que.push(root);
        
        while (!que.empty()) {
            int size = que.size();
            vector<int> level;
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                
                level.push_back(node->val);
                
                if (node->left) {
                    que.push(node->left);
                }
                if (node->right) {
                    que.push(node->right);
                }
            }
            
            result.push_back(level);
        }
        
        return result;
    }
};
