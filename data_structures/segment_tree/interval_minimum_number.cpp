/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */

class MySegmentTreeNode {
    public:
    int start, end, min;
    MySegmentTreeNode *left;
    MySegmentTreeNode *right;
    MySegmentTreeNode(int s, int e, int m):start(s), end(e), min(m) {left = NULL; right = NULL;}
};


class Solution { 
public:
    /**
     *@param A, queries: Given an integer array and an query list
     *@return: The result list
     */
    vector<int> intervalMinNumber(vector<int> &A, vector<Interval> &queries) {
        // write your code here
        vector<int> results;
        if (A.size() == 0) return results;
        MySegmentTreeNode *root = buildHelper(0, A.size()-1, A);
        
        for (int i = 0; i < queries.size(); i++) {
            results.push_back(query(root, queries[i].start, queries[i].end));
        }
        return results;
    }
    // Build min segment tree, add query method
    
    MySegmentTreeNode *buildHelper(int start, int end, vector<int>& A) {
        MySegmentTreeNode *root = new MySegmentTreeNode(start, end, 0);
        if (start == end) {
            root->min = A[start];
            return root;
        } else {
            root->left = buildHelper(start, (start+end)/2, A);
            root->right = buildHelper((start+end)/2 + 1, end, A);
            root->min = ::min(root->left->min, root->right->min);
            return root;
        }
    }
    
    int query(MySegmentTreeNode* root, int start, int end) {
        if (start == root->start && end == root->end) {
            return root->min;
        } else if (end <= root->left->end) {
            return query(root->left, start, end);
        } else if (start >= root->right->start) {
            return query(root->right, start, end);
        } else {
            return ::min(query(root->left, start, root->left->end),
            query(root->right, root->right->start, end));
        }
    }
};
