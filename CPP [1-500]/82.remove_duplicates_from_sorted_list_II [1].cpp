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
    ListNode* deleteDuplicates(ListNode* head) { //S.C.=O(n)
        unordered_map<int,int> mp; //num -> freq
        ListNode *curr= head, *del=NULL;
        while(curr!=NULL)
        {
            mp[curr->val]++;
            curr= curr->next;
        }
        ListNode *dummy= new ListNode(INT_MIN); //dummy node
        dummy->next= head; //connect dummy to 1st node
        curr= dummy;
        while(curr->next!=NULL)
        {
            if(mp[curr->next->val] > 1)
            {
                del= curr->next;
                curr->next= curr->next->next;
                delete del;
            }
            else
                curr= curr->next;
        }
        return dummy->next;
    }
};