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
    ListNode* reverseList(ListNode* head)
    {
        ListNode *prev=NULL, *curr=head, *temp=NULL;
        while(curr!=NULL)
        {
            temp=curr->next; //save the next node of curr
            curr->next=prev; //connect curr->next to prev
            prev=curr; //move prev forward
            curr=temp; //move curr forward
        }
        return prev;
    }
    
    void reorderList(ListNode* head) { //S.C.=O(1)
        if(head->next==NULL) //only 1 node in LL
            return;
        ListNode *prev=NULL, *slow=head, *fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=NULL; //splits the LL into 2 halves
        ListNode *head2=reverseList(slow); //reverse the 2nd half
        ListNode *curr1=head, *curr2=head2;
        ListNode *temp1=NULL, *temp2=NULL;
        while(curr1!=NULL)
        {
            temp1=curr1->next; //save the next node of curr1
            temp2=curr2->next; //save the next node of curr2
            curr1->next=curr2; //connect curr1 to curr2
            if(temp1!=NULL) //LL1 ends (happens when original LL is of odd length)
                curr2->next=temp1; //connect curr2 to nextnode of curr1
            curr1=temp1; //move curr1 forward
            curr2=temp2; //move curr2 forward
        }
    }
};
// Even length LL:
// 1->2->3->4->5->6 splits as 1->2->3 and 4->5->6
// then merge 1->2->3 and 6->5->4 to get 1->6->2->5->3->4
// Odd length LL:
// 1->2->3->4->5 splits as 1->2 and 3->4->5
// then merge 1->2 and 5->4->3 to get 1->5->2->4->3
