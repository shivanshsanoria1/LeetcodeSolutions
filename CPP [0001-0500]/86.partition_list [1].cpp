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
    ListNode* partition(ListNode* head, int x) { //S.C.=O(n)
        vector<int> lesser, greater;
        ListNode *curr=head;
        while(curr!=NULL)
        {
            if(curr->val < x)
                lesser.push_back(curr->val);
            else
                greater.push_back(curr->val);
            curr=curr->next;
        }
        curr=head;
        for(int i=0; i<lesser.size(); i++)
        {
            curr->val=lesser[i];
            curr=curr->next;
        }
        for(int i=0; i<greater.size(); i++)
        {
            curr->val=greater[i];
            curr=curr->next;
        }
        return head;
    }
};