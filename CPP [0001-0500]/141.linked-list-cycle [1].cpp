/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    // Floyd's Cycle Finding algo.
    bool hasCycle(ListNode *head) { 
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast)
                return true;
        }
        
        return false;
    }
};