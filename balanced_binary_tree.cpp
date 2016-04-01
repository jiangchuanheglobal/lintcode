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
  ResultType(bool b, int d) {
      balanced = b;
      depth = d;
  }
  bool balanced;
  int depth;
};

class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode *root) {
        // write your code here
        return helper(root).balanced;
    }
    ResultType helper(TreeNode *root) {
        if (!root) {
            return ResultType(true, 0);
        }
        ResultType left = helper(root->left);
        ResultType right = helper(root->right);
        if (left.balanced &&
        right.balanced &&
        abs(left.depth - right.depth) <= 1) {
            return ResultType(true, max(left.depth, right.depth) + 1);
        } else {
            return ResultType(false, max(left.depth, right.depth) + 1);
        }
    }
