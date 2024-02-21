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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *curr=head;
        int n=0;
        while(curr!=NULL) //find length of LL
        {
            n++;
            curr=curr->next;
        }
        ListNode *node_a=NULL, *node_b=NULL;
        int a=k, b=n-k+1;
        curr=head;
        while(a>0 || b>0) //loop stops when both 'a' and 'b' become <= 0
        {
            a--;
            b--;
            if(a==0) //found node_a
                node_a=curr;
            if(b==0) //found node_b
                node_b=curr;
            curr=curr->next;
        }
        int temp=node_a->val; //swap the values at node_a and node_b
        node_a->val=node_b->val;
        node_b->val=temp;
        return head;
    }
};