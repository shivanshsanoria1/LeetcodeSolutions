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
        int ans=0;
        while(curr!=NULL)
        {
            ans=ans<<1;
            ans+=curr->val;
            curr=curr->next;
        }
        return ans;
    }
};