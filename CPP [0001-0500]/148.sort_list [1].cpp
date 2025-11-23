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
    ListNode* sortList(ListNode* head) { //T.C.=O(nlogn) , S.C.=O(n)
        vector<int> vec;
        ListNode *curr=head;
        while(curr!=NULL)
        {
            vec.push_back(curr->val);
            curr=curr->next;
        }
        sort(vec.begin(),vec.end());
        curr=head;
        for(int i=0; i<vec.size(); i++)
        {
            curr->val=vec[i];
            curr=curr->next;
        }
        return head;
    }
};