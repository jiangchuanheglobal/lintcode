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
     * @aaram a, b, the root of binary trees.
     * @return true if they are tweaked identical, or false.
     */
    bool isTweakedIdentical(TreeNode* a, TreeNode* b) {
        // Write your code here
        if (!a && !b) return true;
        if (!a ^ !b) return false;
        return ((isTweakedIdentical(a->left, b->left) && isTweakedIdentical(a->right, b->right))
        || (isTweakedIdentical(a->left, b->right) && isTweakedIdentical(a->right, b->left)))
        && a->val == b->val;
    }
};
