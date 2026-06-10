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
    // T.C.=O(n), S.C.=O(n)
    ListNode* removeNodes(ListNode* head) {
        // maxVals[i]: max-val to the right of i
        vector<int> maxVals;

        ListNode* curr = head;

        while(curr != nullptr)
        {
            maxVals.push_back(curr->val);
            curr = curr->next;
        }

        for(int i=maxVals.size()-2; i>=0; i--)
            maxVals[i] = max(maxVals[i], maxVals[i+1]);

        ListNode* dummy = new ListNode(-1, head);

        ListNode* prev = dummy;
        curr = head;
        int i = 0;

        while(curr != nullptr)
        {
            if(curr->val < maxVals[i])
            {
                prev->next = curr->next;
                ListNode* del = curr;
                curr = prev->next;
                delete del;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }

            i++;
        }

        ListNode* ret = dummy->next;
        delete dummy;

        return ret;
    }
};