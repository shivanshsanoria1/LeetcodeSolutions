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
    // S.C.=O(n)
    ListNode* reverseList(ListNode* head) { 
        vector<int> vec;

        ListNode* curr = head;
        while(curr != nullptr)
        {
            vec.push_back(curr->val);
            curr = curr->next;
        }
        
        curr = head;
        for(int i=vec.size()-1; i>=0; i--)
        {
            curr->val = vec[i];
            curr = curr->next;
        }
        
        return head;
    }
};