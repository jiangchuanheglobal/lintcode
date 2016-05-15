class Solution {
public:
    /* you may need to use some attributes here */
    

    class SegmentTreeNode {
        public:
         int start, end;
         int sum;
         SegmentTreeNode* left;
         SegmentTreeNode* right;
         SegmentTreeNode(int start, int end, int sum) {
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
    int query(SegmentTreeNode *root, int start, int end) {
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
    void update(SegmentTreeNode* root, int index, int value) {
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
    /**
     * @param A: An integer vector
     */
    Solution(vector<int> A) {
        // write your code here
        int start = 0;
        int end = A.size() - 1;
        root = build(start, end);
        for (int i = 0; i < A.size(); i++) {
            update(root, i, A[i]);
        }
        
    }
    
    /**
     * @param start, end: Indices
     * @return: The sum from start to end
     */
    long long query(int start, int end) {
        // write your code here
        return query(root, start, end);
    }
    
    /**
     * @param index, value: modify A[index] to value.
     */
    void modify(int index, int value) {
        // write your code here
        update(root, index, value);
    }
    
    SegmentTreeNode* root;
};
