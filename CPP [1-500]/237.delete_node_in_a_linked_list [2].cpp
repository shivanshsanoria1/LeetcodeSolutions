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
        ListNode *curr= node;
        while(curr->next->next != NULL) //traverse upto the 2nd last node
        {
            curr->val= curr->next->val; //copy the value of next node to the current node
            curr= curr->next;
        }
        curr->val= curr->next->val; //copy the value of last node to the 2nd last node
        delete curr->next; //delete the last node
        curr->next= NULL;
    }
};