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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) { //with taking extra LL
        if(l1==NULL) //LL1 is empty so return LL2
            return l2;
        if(l2==NULL) //LL2 is empty so return LL1
            return l1;
        ListNode *curr1=l1, *curr2=l2;
        ListNode *dummy = new ListNode(-1); //this is the first node of the final LL
        ListNode *curr = dummy;
        while(curr1!=NULL && curr2!=NULL)
        {
            if(curr1->val <= curr2->val)
            {
                curr->next = new ListNode(curr1->val);
                curr1= curr1->next;
            }
            else
            {
                curr->next = new ListNode(curr2->val);
                curr2= curr2->next;
            }
            curr= curr->next;
        }
        while(curr1!=NULL) //LL1 has more elements remaining
        {
            curr->next = new ListNode(curr1->val);
            curr1= curr1->next;
            curr= curr->next;
        }
        while(curr2!=NULL) //LL2 has more elements remaining
        {
            curr->next = new ListNode(curr2->val);
            curr2= curr2->next;
            curr= curr->next;
        }
        return dummy->next;
    }
};