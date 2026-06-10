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
    // T.C.=O(n), S.C.=O(1)
    // 2-pointer; modifying the original LL
    ListNode* mergeNodes(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* left = head;
        ListNode* right = head;
        int sum = 0;

        while(right != nullptr)
        {
            while(right->val != 0)
            {
                sum += right->val;
                right = right->next;
            }
            
            if(right != head)
            {
                left->val = sum;
                prev = left;
                left = left->next;
                sum = 0;
            }

            right = right->next;
        }

        if(prev != nullptr)
            prev->next = nullptr;

        return head;
    }
};