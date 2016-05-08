/**
 * Definition of ParentTreeNode:
 * class ParentTreeNode {
 * public:
 *     int val;
 *     ParentTreeNode *parent, *left, *right;
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of the tree
     * @param A, B: Two node in the tree
     * @return: The lowest common ancestor of A and B
     */
    ParentTreeNode *lowestCommonAncestorII(ParentTreeNode *root,
                                           ParentTreeNode *A,
                                           ParentTreeNode *B) {
        // Write your code here
        if (!root) return root;
        
        vector<ParentTreeNode*> pathA;
        vector<ParentTreeNode*> pathB;
        // go back to root
        
        while (A) {
            pathA.push_back(A);
            A = A->parent;
        }
        while (B) {
            pathB.push_back(B);
            B = B->parent;
        }
        
        std::reverse(pathA.begin(), pathA.end());
        std::reverse(pathB.begin(), pathB.end());
        int i;
        for (i = 0; i < pathA.size() && i < pathB.size(); i++) {
            if (pathA[i] != pathB[i]) break;
        }
        return pathA[i-1];
    }
};
