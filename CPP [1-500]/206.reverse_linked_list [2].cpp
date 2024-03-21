/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // S.C.=O(1)
    ListNode* reverseList(ListNode* head) { 
        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *nextnode = head;

        while(nextnode != nullptr)
        {
            // store the nextnode
            nextnode = curr->next;
            // make the link from curr to prev 
            curr->next = prev;
            // move prev forward 
            prev = curr;
            // move curr forward
            curr = nextnode; 
        }

        // prev is at last node so make it the new head
        head = prev; 
        
        return head;
    }
};