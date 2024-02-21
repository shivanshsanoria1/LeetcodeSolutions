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
        int len1=0, len2=0;
        while(curr1!=NULL) //find length of LL1
        {
            len1++;
            curr1= curr1->next;
        }
        while(curr2!=NULL) //find length of LL2
        {
            len2++;
            curr2= curr2->next;
        }
        curr1=h1, curr2=h2;
        if(len1 >= len2) //LL1 is longer
        {
            int diff= len1-len2;
            while(diff--) //move curr1 'diff' nodes forward
                curr1= curr1->next;
        }
        else //LL2 is longer
        {
            int diff= len2-len1;
            while(diff--) //move curr2 'diff' nodes forward
                curr2= curr2->next;
        }
        while(curr1!=NULL && curr2!=NULL)
        {
            if(curr1 == curr2)
                return curr1;
            curr1= curr1->next;
            curr2= curr2->next;
        }
        return NULL; //LL1 and LL2 do not intersect
    }
};