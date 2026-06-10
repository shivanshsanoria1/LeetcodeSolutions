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
private:
    // returns {head, tail} of the reversed LL
    pair<ListNode*, ListNode*> reverseLL(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while(curr != nullptr)
        {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return {prev, head};
    }

public:
    // T.C.=O(n), S.C.=O(1)
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(-1, head);

        ListNode* currHeadPrev = dummy;
        ListNode* currTail = head;

        int count = 1;

        while(currTail != nullptr)
        {
            if(count == k)
            {
                // save the next node of tail
                ListNode* temp = currTail->next;
                // detach the tail from LL
                currTail->next = nullptr;

                // reverse the portion of LL starting at curr-head
                // to get the head and tail of reversed LL
                auto [newCurrHead, newCurrTail] = reverseLL(currHeadPrev->next);

                // attach the head and tail of reversed LL to the main LL
                currHeadPrev->next = newCurrHead;
                newCurrTail->next = temp;

                // update the curr head and tail for next iteration
                currHeadPrev = newCurrTail;
                currTail = newCurrTail;

                count = 0;
            }

            currTail = currTail->next;
            count++;
        }

        head = dummy->next;
        delete dummy;
        return head;
    }
};
// prerequisite: [206. reverse-linked-list]