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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* curr = head;
        int n = 0;
        while(curr != NULL)
        {
            n++;
            curr = curr->next;
        }

        vector<ListNode*> ans;
        int groupSize = n / k;
        int rem = n % k;
        curr = head;
        if(curr != NULL)
            ans.push_back(curr);
        int k2 = k;
        while(k2--)
        {
            int currGroupSize = groupSize;
            if(rem > 0)
            {
                currGroupSize++;
                rem--;
            }
            while(curr != NULL && currGroupSize--)
            {
                if(currGroupSize == 0)
                {
                    ListNode* temp = curr->next;
                    curr->next = NULL;
                    curr = temp;
                    if(curr != NULL)
                        ans.push_back(curr);
                }
                else
                    curr = curr->next;
            }
        }
        
        int nulls = k - n;
        while(nulls > 0)
        {
            ans.push_back(NULL);
            nulls--;
        }
        return ans;
    }
};
/*
# num of groups = k
# size of the first n % k groups = n / k + 1
# size of each remaining group = n / k
# if n < k, size of the last k - n  groups is 0
*/