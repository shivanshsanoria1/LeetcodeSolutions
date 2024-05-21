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
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while(curr != nullptr)
        {
            // save the next node of curr
            ListNode* temp = curr->next;
            // connect curr->next to prev
            curr->next = prev;
            // move prev forward 
            prev = curr;
            // move curr forward 
            curr = temp;
        }
        
        return prev;
    }
};