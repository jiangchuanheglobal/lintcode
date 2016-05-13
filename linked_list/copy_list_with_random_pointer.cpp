/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        // write your code here
        RandomListNode* curt = head;
        RandomListNode dummy(0);
        RandomListNode* copyPre = &dummy;
        
        map<int, RandomListNode*> copy_nodes;
        while (curt) {
            RandomListNode* node = new RandomListNode(curt->label);
            copy_nodes[curt->label] = node;
            
            copyPre->next = node;
            
            copyPre = copyPre->next;
            curt = curt->next;
        }
        
        curt = head;
        RandomListNode* node = dummy.next;
        while (curt) {
            if (curt->random) {
                node->random = copy_nodes[curt->random->label];
            }
            
            node = node->next;
            curt = curt->next;
        }
        
        return dummy.next;
    }
};

