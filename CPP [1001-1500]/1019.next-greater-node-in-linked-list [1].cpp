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
    // Monotonic-Stack (decreasing / non-increasing)
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* curr = head;
        vector<int> nums;
        while(curr != nullptr)
        {
            nums.push_back(curr->val);
            curr = curr->next;
        }

        stack<int> st;
        int n=nums.size();
        vector<int> nge(n, 0);
        
        for(int i=0; i<n; i++)
        {
            while(!st.empty() && nums[st.top()] < nums[i])
            {
                nge[st.top()] = nums[i];
                st.pop();
            }
            
            st.push(i);
        }

        return nge;
    }
};