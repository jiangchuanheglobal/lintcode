/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, max;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int max) {
 *         this->start = start;
 *         this->end = end;
 *         this->max = max;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     *@param root, index, value: The root of segment tree and 
     *@ change the node's value with [index, index] to the new given value
     *@return: void
     */
    void modify(SegmentTreeNode *root, int index, int value) {
        // write your code here
        helper(root, index, value);
    }
    
    int helper(SegmentTreeNode *root, int index, int value) {
        if (root->start == root->end && index == root->start) {
            root->max = value;
            return root->max;
        }
        if (index <= root->left->end) {
            int max = helper(root->left, index, value);
            root->max = ::max(max, root->right->max);
            return root->max;
        } else {
            int max = helper(root->right, index, value);
            root->max = ::max(root->left->max, max);
            return root->max;
        }
    }
};
