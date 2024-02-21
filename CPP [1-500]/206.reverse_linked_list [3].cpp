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
        ListNode *prev = NULL, *curr = head, *temp = NULL;
        while(curr != NULL)
        {
            temp = curr->next; // save the next node of curr
            curr->next = prev; // connect curr->next to prev
            prev = curr; // move prev forward
            curr = temp; // move curr forward
        }
        return prev;
    }
};