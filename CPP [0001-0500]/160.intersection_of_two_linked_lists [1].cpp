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
    ListNode *getIntersectionNode(ListNode *h1, ListNode *h2) { //T.C.=O(m*n) , S.C.=O(1) , m and n nodes in LL1 and LL2
        ListNode *curr1=h1, *curr2=h2;
        while(curr1!=NULL)
        {
            curr2=h2;
            while(curr2!=NULL)
            {
                if(curr1 == curr2)
                    return curr1;
                curr2= curr2->next;
            }
            curr1= curr1->next;
        }
        return NULL; //LL1 and LL2 do not intersect
    }
};