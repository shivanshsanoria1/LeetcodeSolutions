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
        vector<int> nums;

        ListNode* curr = head;
        while(curr != nullptr)
        {
            nums.push_back(curr->val);
            curr = curr->next;
        }
        
        curr = head;
        for(int i=nums.size()-1; i>=0; i--)
        {
            curr->val = nums[i];
            curr = curr->next;
        }
        
        return head;
    }
};