/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *h1, ListNode *h2) { //T.C.=O(m+n) , S.C.=O(1) , m and n nodes in LL1 and LL2
        ListNode *curr1=h1, *curr2=h2;
        while(curr1!=NULL) //mark all the nodes in LL1 as visited
        {
            curr1->val *= -1;
            curr1= curr1->next;
        }
        while(curr2!=NULL) //find intersection (if present)
        {
            if(curr2->val < 0)
                break;
            curr2= curr2->next;
        }
        curr1=h1;
        while(curr1!=NULL) //restore all the nodes in LL1
        {
            curr1->val *= -1;
            curr1= curr1->next;
        }
        return curr2;
    }
};