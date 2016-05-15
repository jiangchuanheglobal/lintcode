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
     *@param A: a list of integer
     *@return: The root of Segment Tree
     */
    SegmentTreeNode * build(vector<int>& A) {
        // write your code here
        if (A.size() == 0) return NULL;
        return buildHelper(0, A.size()-1, A);
    }
    SegmentTreeNode * buildHelper(int start, int end, vector<int>& A) {
        SegmentTreeNode *root = new SegmentTreeNode(start, end, 0);
        if (start == end) {
            root->max = A[start];
            return root;
        } else {
            root->left = buildHelper(start, (start+end)/2, A);
            root->right = buildHelper((start+end)/2 + 1, end, A);
            root->max = ::max(root->left->max, root->right->max);
            return root;
        }
    }
};
