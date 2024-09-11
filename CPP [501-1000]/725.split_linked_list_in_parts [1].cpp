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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        for(ListNode* curr = head; curr != nullptr; curr = curr->next)
            n++;

        int groupSize = n / k;
        int rem = n % k;

        vector<ListNode*> ans;
        ListNode* curr = head;

        while(k--)
        {
            int currGroupSize = groupSize;
            if(rem > 0)
            {
                currGroupSize++;
                rem--;
            }

            ans.push_back(curr);

            while(curr != nullptr && currGroupSize--)
            {
                if(currGroupSize == 0)
                {
                    ListNode* temp = curr->next;
                    curr->next = nullptr;
                    curr = temp;
                }
                else
                    curr = curr->next;
            }
        }
    
        return ans;
    }
};

/*
# num of groups = k
# size of the first (n % k) groups = (n / k) + 1
# size of each remaining groups = (n / k)
*/