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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) //LL is of length 0 or 1
            return head;
        ListNode *curr=head;
        int n=1;
        while(curr->next!=NULL) //reach last node
        {
            curr=curr->next; 
            n++; //length of LL
        }
        if(k % n == 0) //no rotation required
            return head;
        curr->next= head; //connect last node to first node to form a CLL
        int rot= n - (k % n);
        while(rot--) //reach to the node where link needs to broken to make the CLL back into LL
            curr=curr->next;
        head= curr->next; //new head
        curr->next= NULL; //break the appropriate link
        return head;
    }
};