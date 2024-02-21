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
    ListNode* reverseList(ListNode* head)
    {
        ListNode *prev=NULL, *curr=head, *nextnode=head;
        while(nextnode!=NULL)
        {
            nextnode= curr->next;
            curr->next= prev;
            prev= curr;
            curr= nextnode;
        }
        head= prev;
        return head;    
    }
    
    ListNode* middleNode(ListNode* head)
    {
        ListNode *slow=head, *fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    
    bool isPalindrome(ListNode* head) { //S.C.=O(1)
        ListNode* mid= middleNode(head); //find middle of the LL
        ListNode *right= reverseList(mid); //reverse the LL from mid till the end
        ListNode *left= head;
        while(right!=NULL)
        {
            if(left->val != right->val)
                return false;
            left= left->next;
            right= right->next;
        }
        return true;
    }
};
// 1->2->3->2->1 has mid=3   and   1->2->3->3->2->1 has mid=3 (second 3)
//       |                                  |
//       mid                                mid
// 1->2->3->2->1 becomes 1->2->3<-2<-1   and   1->2->3->3->2->1 becomes 1->2->3->3<-2<-1
//                             |                                                 |
//                             NULL                                              NULL
// 1->2->3<-2<-1   and   1->2->3->3<-2<-1
// |     |     |         |        |     |
// left  NULL  right     left     NULL  right
