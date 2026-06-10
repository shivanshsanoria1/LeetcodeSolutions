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
    // T.C.=O(n^2), S.C.=O(1)
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        
        ListNode* left = dummy;
        while(left != nullptr)
        {
            int sum = 0;
            ListNode* right = left->next;
            while(right != nullptr)
            {
                sum += right->val;
                if(sum == 0)
                    left->next = right->next;
                right = right->next;
            }
            left = left->next;
        }
        
        return dummy->next;
    }
};