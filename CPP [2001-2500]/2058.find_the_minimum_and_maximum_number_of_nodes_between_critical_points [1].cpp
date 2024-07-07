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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> nums;
        ListNode* curr = head;
        while(curr != nullptr)
        {
            nums.push_back(curr->val);
            curr = curr->next;
        }

        int n=nums.size();
        // LL must have atleast 4 nodes, to have 2 distinct critical-points
        if(n < 4)
            return {-1, -1};

        // index of the 1st critical-point
        int firstIdx = -1;
        // index of the immediate prev critical-point
        int prevIdx = -1;

        int minDist = INT_MAX;
        int maxDist = -1;
        
        for(int i=1; i<n-1; i++)
            if((nums[i-1] < nums[i] && nums[i] > nums[i+1]) || (nums[i-1] > nums[i] && nums[i] < nums[i+1]))
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

        if(minDist == INT_MAX)
            minDist = -1;

        return {minDist, maxDist};
    }
};