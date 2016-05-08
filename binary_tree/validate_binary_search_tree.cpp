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
 
class ResultType {
    public:
    ResultType(bool b, int _min, int _max) {
        isValid = b;
        minVal = _min;
        maxVal = _max;
    }
    bool isValid;
    int minVal;
    int maxVal;
};

class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode *root) {
        // write your code here
        ResultType result = helper(root);
        return result.isValid;
    }
    ResultType helper(TreeNode *root) {
        if (!root) {
         return ResultType(true, INT_MAX, INT_MIN);   
        }
        ResultType leftResult = helper(root->left);
        ResultType rightResult = helper(root->right);
        if (!leftResult.isValid || !rightResult.isValid) {
            return ResultType(false, 0, 0);
        }
        if ( (root->left && root->val <= leftResult.maxVal)
        || (root->right && root->val >= rightResult.minVal) ) {
            return ResultType(false, 0, 0);
        }
       
        return ResultType(true, min(leftResult.minVal, root->val),
        max(rightResult.maxVal, root->val));
       
    }
