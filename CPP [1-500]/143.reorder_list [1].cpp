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
    void reorderList(ListNode* head) { //S.C.=O(n)
        vector<int> vec;
        ListNode *curr=head;
        while(curr!=NULL)
        {
            vec.push_back(curr->val);
            curr=curr->next;
        }
        curr=head;
        int left=0, right=vec.size()-1;
        while(left < right)
        {
            curr->val=vec[left];
            curr=curr->next;
            curr->val=vec[right];
            curr=curr->next;
            left++;
            right--;
        }
        if(left == right)
            curr->val=vec[left];
    }
};