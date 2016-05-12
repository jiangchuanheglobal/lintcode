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
     * @param A: Given an integer array with no duplicates.
     * @return: The root of max tree.
     */
    TreeNode* maxTree(vector<int> A) {
        // write your code here
        vector<TreeNode*> stk;
        for (int i = 0; i < A.size(); i++) {
            TreeNode* tmp = new TreeNode(A[i]);
            while (stk.size() > 0 && A[i] > stk.back()->val) {
                tmp->left = stk.back();
                stk.pop_back();
            }
            if (stk.size() > 0) {
                stk.back()->right = tmp;
            }
            stk.push_back(tmp);
        }
        return stk[0];
    }
};
