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
    // 2-pointer; creating a new LL
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;

        ListNode* left = head;
        ListNode* right = head;
        int sum = 0;

        while(right != nullptr)
        {
            sum += right->val;
            
            if(right->val == 0 && right != head)
            {
                ListNode* newNode = new ListNode(sum);
                curr->next = newNode;
                curr = curr->next;
                
                sum = 0;
                left = right;
            }

            right = right->next;
        }

        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};
// S.C. does not include the space taken by the new LL