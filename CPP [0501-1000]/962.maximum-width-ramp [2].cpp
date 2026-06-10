class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    // Monotonic-stack (strictly-decreasing)
    int maxWidthRamp(vector<int>& nums) {
        int n=nums.size();

        // stack stores indexes and not values
        stack<int> st;
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

// similar: [739. daily-temperatures]