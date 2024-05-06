/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // T.C.=O(1)
    void deleteNode(ListNode* node) {
        // next node of the curr node
        ListNode* nextNode = node->next;
        // copy the next node's val to curr node
        node->val = nextNode->val;
        // connect curr node to next node's next
        node->next = nextNode->next;
        // delete the next node
        delete nextNode;
    }
};