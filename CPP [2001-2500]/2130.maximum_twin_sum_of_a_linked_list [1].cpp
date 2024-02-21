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
    int pairSum(ListNode* head) { // T.C.=O(n), S.C.=O(n)
        ListNode *curr= head;
        vector<int> vec;
        while(curr != NULL)
        {
            vec.push_back(curr->val);
            curr=curr->next;
        }
        int n= vec.size();
        int ans= INT_MIN;
        for(int i=0; i<=n/2; i++)
            ans= max(ans, vec[i]+vec[n-i-1]);
        return ans;
    }
};