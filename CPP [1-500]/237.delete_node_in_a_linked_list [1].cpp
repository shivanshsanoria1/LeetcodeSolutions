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
    void deleteNode(ListNode* node) {
        ListNode *del;
        node->val= node->next->val; //copy the value of next node to the given node
        del= node->next; //delete the next node of the given node
        node->next= node->next->next; //skip the next node of given node
        delete del;
    }
};