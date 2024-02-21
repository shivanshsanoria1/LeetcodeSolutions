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
    ListNode* deleteDuplicates(ListNode* head) { //S.C.=O(1)
        ListNode *dummy= new ListNode(INT_MIN); //dummy node
        dummy->next= head; //connect dummy to 1st node
        ListNode *prev=dummy, *curr= head;
        while(curr!=NULL)
        {
            bool flag= false;
            while(curr->next!=NULL && curr->val==curr->next->val) //remove all duplicates of curr element
            {
                flag= true;
                prev->next= curr->next;
                delete curr;
                curr= prev->next;
            }
            if(flag==true) //delete the remaining occurence of the repeated element
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