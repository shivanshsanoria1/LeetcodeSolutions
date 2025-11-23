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
    ListNode* reverseLL(ListNode* head) {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *temp = nullptr;

        while(curr != nullptr)
        {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        head = prev;
        return head;    
    }
    
    ListNode* getMiddleNode(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

public:
    // S.C.=O(1)
    bool isPalindrome(ListNode* head) { 
        // find middle of the LL
        ListNode *mid = getMiddleNode(head);
        // reverse the LL from mid till the end
        ListNode *right= reverseLL(mid); 

        ListNode *left = head;
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
/*

# after mid is found (in case of even length LL, 2nd mid is considered)
  1->2->3->2->1   and   1->2->3->3->2->1
        ^                        ^
        |                        |
        mid                      mid

# after reversal
  1->2->3<-2<-1   and   1->2->3->3<-2<-1
        |                        |
        v                        v
        NULL                     NULL

# starting to check if LL is palindrome
  1->2->3<-2<-1   and   1->2->3->3<-2<-1
  ^     |     ^         ^        |     ^ 
  |     v     |         |        v     |
  left  NULL  right     left     NULL  right

*/
