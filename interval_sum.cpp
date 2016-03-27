/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class Solution { 
public:
    /**
     *@param A, queries: Given an integer array and an query list
     *@return: The result list
     */
    class SegmentTreeNode {
        public:
         int start, end;
         long long sum;
         SegmentTreeNode* left;
         SegmentTreeNode* right;
         SegmentTreeNode(int start, int end, long long sum) {
              this->start = start;
              this->end = end;
              this->sum = sum;
              this->left = this->right = NULL;
        }
    };
    SegmentTreeNode * build(int start, int end) {
        // write your code here
        if (start > end) return NULL;
        SegmentTreeNode *root = new SegmentTreeNode(start, end, 0);
        if (start == end) {
            return root;
        } else {
            root->left = build(start, (start+end)/2);
            root->right = build((start+end)/2 + 1, end);
            return root;
        }
    }
    long long query(SegmentTreeNode *root, int start, int end) {
        // write your code here
        if (!root) return 0;
        
        // sanify [start, end] range
        if (start > root->end) {
            return 0;
        } else if (end < root->start) {
            return 0;
        } else if (start < root->start) {
            start = root->start;
        } else if (end > root->end) {
            end = root->end;
        }
        
        if (start == root->start && end == root->end) {
            return root->sum;
        } else if (end <= root->left->end) {
            return query(root->left, start, end);
        } else if (start >= root->right->start) {
            return query(root->right, start, end);  
        } else {
            return query(root->left, start, root->left->end) + query(root->right, root->right->start, end);
        }
    }
    void update(SegmentTreeNode* root, int index, long long value) {
        if (root->start == index && root->end == index) {
            root->sum = value;
            return;
        }
        
        int mid = (root->start + root->end) / 2;
        
        if (root->start <= index && index <= mid) {
           update(root->left, index, value); 
        } else if (mid < index && index <= root->end) {
            update(root->right, index, value);
        }
        root->sum = root->left->sum + root->right->sum;
    }
    
    vector<long long> intervalSum(vector<int> &A, vector<Interval> &queries) {
        // write your code here
        SegmentTreeNode* root = NULL;
        int start = 0;
        int end = A.size() - 1;
        root = build(start, end);
        for (int i = 0; i < A.size(); i++) {
            update(root, i, A[i]);
        }
        
        vector<long long> ans;
        for (auto& i : queries) {
            ans.push_back(query(root, i.start, i.end));
        }
        return ans;
    }
    
};
