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
    ListNode* removeNthFromEnd(ListNode* head, int n) { //1 pass soln.
        ListNode *dummy = new ListNode(-1); //create a dummy node
        dummy->next= head; //connect dummy node to 1st node
        ListNode *first=dummy, *second=head;
        for(int i=1; i<=n; i++) //to generate a gap of n b/w first and second pointers
            second= second->next;
        while(second!=NULL)
        {
            first= first->next;
            second= second->next;
        }
        ListNode *del= first->next; //node to be deleted
        first->next=first->next->next; //skip the node to be deleted
        delete del;
        return dummy->next;
    }
};