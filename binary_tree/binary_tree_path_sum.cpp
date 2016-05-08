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
     * @param root the root of binary tree
     * @param target an integer
     * @return all valid paths
     */
    vector<vector<int>> binaryTreePathSum(TreeNode *root, int target) {
        // Write your code here
        vector<vector<int>> result;
        vector<int> path;
        helper(result, path, root, target, 0);
        return result;
    }
    
    // 
    void helper(vector<vector<int>>& result, vector<int> path, TreeNode* root, int target, int sum) {
        if (!root) return;
        
        sum += root->val;
        path.push_back(root->val);
        if (!root->left && !root->right) {
            // leaf node
            if (target == sum) result.push_back(path);
            return;
        }
        
        helper(result, path, root->left, target, sum);
        helper(result, path, root->right, target, sum);
    }
};

// 分治法 递归函数需要自然定义
// 一般递归函数也需要自然定义！！！
// 二叉树理解技巧之使用dummy node
