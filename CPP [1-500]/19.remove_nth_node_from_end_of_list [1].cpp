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
    ListNode* removeNthFromEnd(ListNode* head, int n) { //2 pass soln.
        int len=0;
        ListNode *curr= head;
        while(curr!=NULL) //find length of LL
        {
            len++;
            curr= curr->next;
        }
        ListNode *dummy = new ListNode(-1); //create a dummy node
        dummy->next= head; //connect dummy node to 1st node
        curr= dummy; //start curr from dummy
        for(int i=0; i<len-n; i++) //move curr forward (len-n) times
            curr=curr->next;
        ListNode *del= curr->next; //node to be deleted
        curr->next= curr->next->next; //skip the node to be deleted
        delete del;
        return dummy->next;
    }
};