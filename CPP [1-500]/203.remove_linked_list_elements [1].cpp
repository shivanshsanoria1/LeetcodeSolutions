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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy= new ListNode(-1); //dummy node
        dummy->next= head; //connect dummy node to the 1st node
        ListNode *prev= dummy, *curr= head;
        while(curr!=NULL)
        {
            if(curr->val == val)
            {
                prev->next= curr->next;
                delete curr;
                curr= prev->next;
            }
            else
            {
                prev= curr;
                curr= curr->next;
            }
        }
        return dummy->next;
    }
};