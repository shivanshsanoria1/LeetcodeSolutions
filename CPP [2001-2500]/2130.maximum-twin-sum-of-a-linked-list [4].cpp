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
    ListNode *reverseLL(ListNode *head)
    {
        ListNode *prev= NULL, *curr= head , *temp= NULL;
        while(curr != NULL)
        {
            temp= curr->next;
            curr->next= prev;
            prev= curr;
            curr= temp;
        }
        return prev;
    }

    int pairSum(ListNode* head) { // T.C.=O(n), S.C.=O(1)
        // find the middle node
        ListNode *slow= head, *fast= head, *prev= NULL; // prev and slow store the 1st and 2nd mid of LL resp.
        while(fast != NULL) // the condition fast->next != NULL is not required as LL is of even length
        {
            prev= slow;
            slow= slow->next;
            fast= fast->next->next;
        }
        // attach the reversed 2nd half to the 1st half of LL
        prev->next = reverseLL(slow);
        slow= prev->next; // update the 2nd mid (slow)
        // find the max twin sum
        int ans= INT_MIN;
        ListNode *curr1= head, *curr2= slow;
        while(curr1 != slow)
        {
            ans= max(ans, curr1->val + curr2->val);
            curr1= curr1->next;
            curr2= curr2->next;
        }
        // [not required step: restore the original LL] 
        // by reversing the 2nd half again and attaching it to the 1st half
        prev->next = reverseLL(slow);
        return ans;
    }
};