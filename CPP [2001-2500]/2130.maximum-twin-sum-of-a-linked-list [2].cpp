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
    int pairSum(ListNode* head) { // T.C.=O(n), S.C.=O(n)
        // find the middle node
        ListNode *slow= head, *fast= head;
        while(fast != NULL) // the condition fast->next != NULL is not required as LL is of even length
        {
            slow= slow->next;
            fast= fast->next->next;
        }
        // push the 2nd half of LL into a vector
        vector<int> vec;
        ListNode *curr= slow;
        while(curr != NULL)
        {
            vec.push_back(curr->val);
            curr= curr->next;
        }
        // find the max twin sum
        int ans= INT_MIN;
        int i= vec.size()-1;
        curr= head;
        while(curr != slow)
        {
            ans= max(ans, curr->val + vec[i]);
            i--;
            curr= curr->next;
        }
        return ans;
    }
};