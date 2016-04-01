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
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int maxPathSum(TreeNode *root) {
        // write your code here
        int maxVal = INT_MIN;
        helper(root, maxVal);
        return maxVal;
    }
    
    int helper(TreeNode *root, int& maxVal) {
        if (!root) {
            return 0;
        }
        
        int leftMax = helper(root->left, maxVal);
        int rightMax = helper(root->right, maxVal);
        int temp = max(root->val, max(root->val+leftMax, root->val+rightMax));
        maxVal = max(maxVal, temp);
        maxVal = max(maxVal, root->val + leftMax + rightMax);
        return temp;
    }
