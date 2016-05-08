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
 
// 分治法
class ResultType {
public:
    ResultType(bool full, bool complete, int dep) {
        isFull = full;
        isComplete = complete;
        depth = dep;
    }
    bool isFull;
    bool isComplete;
    int depth;
};

class Solution {
public:
    /**
     * @param root, the root of binary tree.
     * @return true if it is a complete binary tree, or false.
     */
    bool isComplete(TreeNode* root) {
        // Write your code here
        return helper(root).isComplete;
    }
    
    ResultType helper(TreeNode* root) {
        if (!root) return ResultType(true, true, 0);
        
        ResultType left = helper(root->left);
        ResultType right = helper(root->right);
        
        if (!left.isComplete || !left.isComplete) {
            return ResultType(true, false, 0);
        }
        
        if (left.depth < right.depth || left.depth - right.depth > 1) {
            return ResultType(true, false, 0);
        }
        
        if ( left.depth == right.depth
        && (!left.isFull || !right.isComplete) ) {
            return ResultType(true, false, 0);
        }
        
        if ( left.depth - right.depth == 1
        && (!right.isFull || !left.isComplete) ){
            return ResultType(true, false, 0);
        }
        
        return ResultType(left.depth == right.depth ? true : false,
                        true, ::max(left.depth, right.depth) + 1);
    }
    
};
