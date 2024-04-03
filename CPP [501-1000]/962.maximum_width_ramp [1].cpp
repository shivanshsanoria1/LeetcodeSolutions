class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    // Monotonic-stack (maintain the stack in decreasing order)
    int maxWidthRamp(vector<int>& nums) {
        // stack stores indexes and not values
        stack<int> st;

        int n=nums.size();

        st.push(0);
        for(int i=1; i<n; i++)
            if(nums[st.top()] > nums[i])
                st.push(i);
        
        int maxWidth = 0;

        for(int i=n-1; i>=0 && !st.empty(); i--)
            while(!st.empty() && nums[st.top()] <= nums[i])
            {
                maxWidth = max(maxWidth, i - st.top());
                st.pop();
            }
        
        return maxWidth;
    }
};