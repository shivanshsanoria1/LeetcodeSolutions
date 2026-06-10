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
    int getDecimalValue(ListNode* head) {
        ListNode *curr=head;
        int n=0, ans=0;
        while(curr!=NULL)
        {
            n++;
            curr=curr->next;
        }
        int mul=pow(2,n-1);
        curr=head;
        while(curr!=NULL)
        {
            ans=ans+(mul*curr->val);
            curr=curr->next;
            mul/=2;
        }
        return ans;
    }
};