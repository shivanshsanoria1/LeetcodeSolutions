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
    ListNode* deleteMiddle(ListNode* head){ //2 pass
        if(head->next==NULL) //only 1 node in LL
        {
            delete head;
            return NULL;
        }
        ListNode *curr=head;
        int n=0;
        while(curr!=NULL)
        {
            n++;
            curr=curr->next;
        }
        n=n/2-1;
        curr=head;
        while(n--)
            curr=curr->next;
        ListNode *del=curr->next;
        curr->next=curr->next->next;
        delete del;
        return head;
    }
};