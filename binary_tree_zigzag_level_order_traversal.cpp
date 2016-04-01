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
     * @return: A list of lists of integer include 
     *          the zigzag level order traversal of its nodes' values 
     */
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        // write your code here
        vector<vector<int>> result;
        if (!root) return result;
        
        stack<TreeNode*> curtLevel;
        stack<TreeNode*> nextLevel;
        stack<TreeNode*> emptyStk;
        
        curtLevel.push(root);
        bool normalOrder = true;
        while (!curtLevel.empty()) {
            
            vector<int> level;
            while (!curtLevel.empty()) {
                TreeNode* node = curtLevel.top();
                curtLevel.pop();
                
                level.push_back(node->val);
                
                if (normalOrder) {
                    if (node->left) {
                        nextLevel.push(node->left);
                    }
                    if (node->right) {
                        nextLevel.push(node->right);
                    }
                } else {
                    if (node->right) {
                        nextLevel.push(node->right);
                    }
                    if (node->left) {
                        nextLevel.push(node->left);
                    }
                }
            }
            
            curtLevel = nextLevel;
            nextLevel = emptyStk;
            
            result.push_back(level);
            normalOrder = !normalOrder;
        }
        
        return result;
    }
};
