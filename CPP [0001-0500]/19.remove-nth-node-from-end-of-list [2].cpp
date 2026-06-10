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
    // 1 pass soln.
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // create a dummy node
        ListNode *dummy = new ListNode(-1);
        // connect dummy node to 1st node
        dummy->next = head; 

        ListNode *first = dummy, *second = head;
        // generate a gap of n b/w first and second pointers
        for(int i=1; i<=n; i++) 
            second = second->next;

        while(second != NULL)
        {
            first = first->next;
            second = second->next;
        }
        
        // node to be deleted
        ListNode *del = first->next; 
        // skip the node to be deleted
        first->next = first->next->next; 
        // delete the nth node
        delete del;
        
        return dummy->next;
    }
};