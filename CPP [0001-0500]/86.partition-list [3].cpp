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
    ListNode* partition(ListNode* head, int x) { //S.C.=O(1)
        ListNode *head1 = new ListNode(-1); //dummy node for LL1
        ListNode *head2 = new ListNode(-1); //dummy node for LL2
        ListNode *curr1=head1, *curr2=head2;
        ListNode *curr=head;
        while(curr!=NULL)
        {
            if(curr->val < x)
            {
                curr1->next=curr; //add curr node to LL1
                curr1=curr; //move curr1 forward
            }
            else
            {
                curr2->next=curr; //add curr node to LL2
                curr2=curr; //move curr2 forward
            }
            curr=curr->next; //move curr forward
        }
        curr2->next=NULL; //end point of LL2
        curr1->next=head2->next; //connect last node of LL1 to the first node of LL2
        return head1->next;
    }
};
//split the LL into LL1 and LL2
//LL1 is for nodes with value < x
//LL2 is for nodes with value >= x