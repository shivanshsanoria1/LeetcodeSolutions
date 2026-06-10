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
private:
    ListNode* reverseLL(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* temp = nullptr;

        while(curr != nullptr)
        {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }

public:
    // T.C.=O(n), S.C.=O(1)
    ListNode* removeNodes(ListNode* head) {
        head = reverseLL(head);

        ListNode* prev = head;
        ListNode* curr = head;
        int maxVal = curr->val;

        while(curr != nullptr)
        {
            if(curr->val < maxVal)
            {
                prev->next = curr->next;
                ListNode* del = curr;
                curr = prev->next;
                delete del;
            }
            else
            {
                maxVal = curr->val;
                prev = curr;
                curr = curr->next;
            }
        }

        head = reverseLL(head);

        return head;
    }
};