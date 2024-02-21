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
    bool isPalindrome(ListNode* head) { //S.C.=O(n)
        vector<int> vec;
        ListNode* curr=head;
        while(curr!=NULL)
        {
            vec.push_back(curr->val);
            curr=curr->next;
        }
        int n=vec.size();
        for(int i=0; i<n; i++)
            if(vec[i] != vec[n-1-i])
                return false;
        return true;
    }
};