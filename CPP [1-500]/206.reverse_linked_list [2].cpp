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
    ListNode* reverseList(ListNode* head) { // S.C.=O(1)
        ListNode *prev = NULL, *curr = head, *nextnode = head;
        while(nextnode != NULL)
        {
            nextnode = curr->next; // store the nextnode
            curr->next = prev; // make the link from curr to prev
            prev = curr; // move prev forward
            curr = nextnode; // move curr forward
        }
        head = prev; // prev is at last node so make it the new head
        return head;
    }
};