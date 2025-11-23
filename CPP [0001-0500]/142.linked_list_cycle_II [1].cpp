/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode* startOfCycle(ListNode* head, ListNode* start2){
        ListNode* start1 = head;
        while(start1 != start2)
        {
            start1 = start1->next;
            start2 = start2->next;
        }

        return start1;
    }

public:
    // T.C.=O(n), S.C.=O(1)
    // Floyd's Cycle Finding algo.
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast)
                return startOfCycle(head, slow);
        }
        
        return nullptr;
    }
};