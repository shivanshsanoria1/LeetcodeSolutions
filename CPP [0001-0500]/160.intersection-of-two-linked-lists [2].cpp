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
    ListNode *getIntersectionNode(ListNode *h1, ListNode *h2) { //T.C.=O(m+n) , S.C.=O(m) , m and n nodes in LL1 and LL2
        unordered_set<ListNode*> s;
        ListNode *curr1=h1, *curr2=h2;
        while(curr1!=NULL)
        {
            s.insert(curr1);
            curr1= curr1->next;
        }
        while(curr2!=NULL)
        {
            if(s.find(curr2) != s.end()) //curr2 present in set
                return curr2;
            curr2= curr2->next;
        }
        return NULL; //LL1 and LL2 do not intersect
    }
};