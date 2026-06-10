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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) { //without taking extra LL
        if(l1==NULL) //LL1 is empty so return LL2
            return l2;
        if(l2==NULL) //LL2 is empty so return LL1
            return l1;
        ListNode *curr1=l1, *curr2=l2;
        ListNode *dummy= new ListNode(INT_MIN); //dummy node
        ListNode *curr= dummy; //curr points to dummy node
        while(curr1!=NULL && curr2!=NULL)
        {
            if(curr1->val <= curr2->val)
            {
                curr->next= curr1;
                curr1= curr1->next;
            }
            else
            {
                curr->next= curr2;
                curr2= curr2->next;
            }
            curr= curr->next;
        }
        if(curr1!=NULL) //nodes are left in LL1
            curr->next= curr1;
        if(curr2!=NULL) //nodes are left in LL2
            curr->next= curr2;
        return dummy->next;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) { //T.C.=O(n*k) , S.C.=O(1) , where n is the max length of LL
        ListNode *head= NULL;
        for(int i=0; i<lists.size(); i++)
            head= mergeTwoLists(head,lists[i]);
        return head;
    }
};
// using the code from Leetvode-21 (merge_two_sorted_lists)