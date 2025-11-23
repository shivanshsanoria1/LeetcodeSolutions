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
    void reverseLL(ListNode* startPrev, ListNode* start, ListNode* end, ListNode* endNext){
        ListNode* prev = endNext;
        ListNode* curr = start;
        ListNode* temp = NULL;
        while(curr != endNext)
        {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        startPrev->next = prev;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy = new ListNode(-501);
        dummy->next = head;
        ListNode* curr = dummy;

        int count = 0;
        ListNode *revStart = NULL, *revEnd = NULL;
        ListNode *revStartPrev = NULL, *revEndNext = NULL;

        while(curr != NULL)
        {
            if(count == left - 1)
                revStartPrev = curr;
            else if(count == left)
                revStart = curr;

            if(count == right)
                revEnd = curr;
            else if(count == right + 1)
                revEndNext = curr;

            curr = curr->next;
            count++;
        }
        
        reverseLL(revStartPrev, revStart, revEnd, revEndNext);

        head = dummy->next;
        delete(dummy);
        return head;
    }
};