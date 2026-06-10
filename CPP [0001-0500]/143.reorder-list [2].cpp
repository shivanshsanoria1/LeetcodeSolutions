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
        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *temp = nullptr;

        while(curr != nullptr)
        {
            // save the next node of curr
            temp = curr->next; 
            // connect curr->next to prev
            curr->next = prev; 
            // move prev forward
            prev = curr; 
            // move curr forward
            curr = temp; 
        }

        return prev;
    }

public:
    // S.C.=O(1)
    void reorderList(ListNode* head) { 
        // only 1 node in LL
        if(head->next == nullptr) 
            return;

        ListNode *prev = nullptr;
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast != nullptr && fast->next != nullptr)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // split the LL into 2 halves
        prev->next = nullptr; 
        // reverse the 2nd half
        ListNode *head2 = reverseLL(slow); 

        ListNode *curr1 = head, *curr2 = head2;
        ListNode *temp1 = nullptr, *temp2 = nullptr;

        while(curr1 != nullptr)
        {
            // save the next node of curr1 and curr2
            temp1 = curr1->next; 
            temp2 = curr2->next;

            // connect curr1 to curr2
            curr1->next = curr2;

            // LL1 ends (happens when original LL is of odd length)
            if(temp1 != nullptr) 
                // connect curr2 to nextnode of curr1
                curr2->next = temp1; 
            
            //move curr1 and curr2 forward
            curr1 = temp1; 
            curr2 = temp2;
        }
    }
};
/*

Even length LL:
1->2->3->4->5->6 splits as 1->2->3 and 4->5->6
then merge 1->2->3 and 6->5->4 to get 1->6->2->5->3->4

Odd length LL:
1->2->3->4->5 splits as 1->2 and 3->4->5
then merge 1->2 and 5->4->3 to get 1->5->2->4->3

*/
