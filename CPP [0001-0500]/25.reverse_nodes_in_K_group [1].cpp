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
    // T.C.=O(n), S.C.=O(n)
    ListNode* reverseKGroup(ListNode* head, int k) {
        // add all node values to a vector
        vector<int> nums;
        ListNode* curr = head;
        while(curr != nullptr)
        {
            nums.push_back(curr->val);
            curr = curr->next;
        }
        
        // reverse the vector values in groups of size k
        int left = 0, right = 0;
        int count = 1;
        while(right < nums.size())
        {
            if(count == k)
            {
                // reverse the vector in index-range [left, right]
                reverse(nums.begin() + left, nums.begin() + right + 1);
                left = right + 1;
                count = 0;
            }
            count++;
            right++;
        }

        // update the LL values with vector values
        curr = head;
        for(int num: nums)
        {
            curr->val = num;
            curr = curr->next;
        }
        
        return head;
    }
};