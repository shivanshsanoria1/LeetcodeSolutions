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
    // 2 pass soln.
    ListNode* removeNthFromEnd(ListNode* head, int n) { 
        int len = 0;
        ListNode *curr = head;
        // find length of the LL
        while(curr != NULL) 
        {
            len++;
            curr = curr->next;
        }

        // create a dummy node
        ListNode *dummy = new ListNode(-1); 
        // connect dummy node to 1st node
        dummy->next = head;
        // start curr from dummy 
        curr = dummy; 

        //move curr forward (len-n) times
        for(int i=1; i<=len-n; i++) 
            curr = curr->next;
        // node to be deleted
        ListNode *del = curr->next; 
        // skip the node to be deleted
        curr->next = curr->next->next; 
        // delete the nth node
        delete del;

        return dummy->next;
    }
};