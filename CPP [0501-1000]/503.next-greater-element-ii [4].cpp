class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    // Monotonic-Stack (decreasing)
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        // stores indexes instead of values
        stack<int> st; 
        vector<int> nge(n, -1);

        for(int i=0; i<2*n; i++)
        {
            int idx = i % n;
            while(!st.empty() && nums[st.top()] < nums[idx])
            {
                nge[st.top()] = nums[idx];
                st.pop();
            }
            
            st.push(idx);
        }

        return nge;
    }
};