Count of Smaller Number before itself

class Solution {
public:
   /**
     * @param A: An integer array
     * @return: Count the number of element before this element 'ai' is 
     *          smaller than it and return count number array
     */
    class SegmentTreeNode {
        public:
         int start, end;
         int count;
         SegmentTreeNode* left;
         SegmentTreeNode* right;
         SegmentTreeNode(int start, int end, int count) {
              this->start = start;
              this->end = end;
              this->count = count;
              this->left = this->right = NULL;
        }
    };
    
    vector<int> countOfSmallerNumberII(vector<int> &A) {
        // write your code here
        int minVal = INT_MAX;
        int maxVal = INT_MIN;
        for (auto& a : A) {
            minVal = ::min(minVal, a);
            maxVal = ::max(maxVal, a);
        }
        
        SegmentTreeNode* root = build(minVal, maxVal);
        
        
        // This is a tricky part !!!
        // query and at the same time update tree
        vector<int> ans;
        for (auto& a : A) {
            ans.push_back(query(root, 0, a - 1));
            update(root, a);
        }
        return ans;
    }
    
    void update(SegmentTreeNode* root, int val) {
       SegmentTreeNode* cur = root;
        
        while (cur) {
            cur->count += 1;
            
            if (!cur->left) return;
            if (!cur->right) return;
            
            if (val <= cur->left->end) {
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }
    }
    
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
            return root->count;
        } else if (end <= root->left->end) {
            return query(root->left, start, end);
        } else if (start >= root->right->start) {
            return query(root->right, start, end);  
        } else {
            return query(root->left, start, root->left->end) + query(root->right, root->right->start, end);
        }
    }
};
