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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        // LL must have atleast 4 nodes, to have 2 distinct critical-points
        if(head->next == nullptr || head->next->next == nullptr)
            return {-1, -1};

        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* nxt = head->next->next;

        // index of the 1st critical-point
        int firstIdx = -1;
        // index of the immediate prev critical-point
        int prevIdx = -1;
        // index of curr
        int i = 1;

        int minDist = INT_MAX;
        int maxDist = -1;

        while(nxt != nullptr)
        {
            if((prev->val < curr->val && curr->val > nxt->val) || (prev->val > curr->val && curr->val < nxt->val))
            {
                if(firstIdx != -1)
                {
                    maxDist = max(maxDist, i - firstIdx);
                    minDist = min(minDist, i - prevIdx);
                }
                else
                    firstIdx = i;

                prevIdx = i;
            }
            
            prev = curr;
            curr = nxt;
            nxt = nxt->next;
            i++;
        }
        
        if(minDist == INT_MAX)
            minDist = -1;

        return {minDist, maxDist};
    }
};