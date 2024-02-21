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
    ListNode* reverseLL(ListNode* head) {
        ListNode *prev = NULL, *curr = head, *temp = NULL;
        while(curr != NULL)
        {
            temp = curr->next; 
            curr->next = prev;
            prev = curr; 
            curr = temp;
        }
        return prev;
    }

public:
    ListNode* doubleIt(ListNode* head) { // S.C.=O(1)
        head = reverseLL(head);
        ListNode *curr = head, *prev = NULL;
        int carry = 0;
        while(curr != NULL)
        {
            
            int newVal = curr->val * 2 % 10 + carry;
            carry = curr->val * 2 / 10;
            curr->val = newVal;
            prev = curr;
            curr = curr->next;
        }
        if(carry == 1)
        {
            ListNode *newNode = new ListNode(1);
            prev->next = newNode;
        }
        return reverseLL(head);
    }
};
// code used from [206. Reverse Linked List]