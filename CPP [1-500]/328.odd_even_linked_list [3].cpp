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
    ListNode* oddEvenList(ListNode* head) { //S.C.=O(1)
        if(head==NULL) //empty LL
            return head;
        ListNode *odd=head;
        ListNode *even=head->next;
        ListNode *even_head=even;
        while(even!=NULL && even->next!=NULL)
        {
            odd->next=even->next;
            odd=odd->next;
            even->next=odd->next;
            even=even->next;
        }
        odd->next=even_head;
        return head;
    }
};
//split the LL into 2 parts odd and even
//odd LL starts at 'head'
//even LL starts at 'even_head'
//connect the end of odd LL to the head of even LL