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
     *@param preorder : A list of integers that preorder traversal of a tree
     *@param inorder : A list of integers that inorder traversal of a tree
     *@return : Root of a tree
     */
public:

    
    TreeNode* helper(vector<int> &pre, vector<int>& in,
    int preStart, int preEnd, int inStart, int inEnd) {
        if (preStart > preEnd) return NULL;
        
        int i;
        for (i = inStart; i <= inEnd; i++) {
            if (pre[preStart] == in[i]) break;
        }
        
        int leftSize = i - inStart;
        
        TreeNode* root = new TreeNode(pre[preStart]);
        root->left = helper(pre, in, 
        preStart + 1, preStart + leftSize, 
        inStart, inStart + leftSize - 1);
        
        root->right = helper(pre, in,
        preStart + leftSize + 1, preEnd,
        inStart + leftSize + 1, inEnd);
        
        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // write your code here
        return helper(preorder, inorder, 0, preorder.size() - 1, 
        0, inorder.size() - 1);
    }
};
