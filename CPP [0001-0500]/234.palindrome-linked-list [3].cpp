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
    // S.C.=O(1)
    bool isPalindrome(ListNode* head) {
        // find the middle node, ie, 'slow'
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast != nullptr && fast->next != nullptr) 
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse LL from 'slow' to end
        ListNode *prev = nullptr;
        ListNode *temp = nullptr;
        while(slow != nullptr) 
        {
            temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }

        // check the non-reversed and the reversed halves
        ListNode *left = head;
        ListNode *right = prev;
        while(right != nullptr) 
        {
            if(left->val != right->val)
                return false;
            left = left->next;
            right = right->next;
        }

        return true;
    }
};