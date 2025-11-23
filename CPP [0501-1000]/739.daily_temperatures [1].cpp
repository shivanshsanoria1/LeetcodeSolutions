class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    // Monotonic-stack (strictly-decreasing)
    vector<int> dailyTemperatures(vector<int>& temperatures) { 
        int n = temperatures.size();
        vector<int> ans(n, 0);
        // stack stores indexes and not values
        stack<int> st; 

        for(int i=n-1; i>=0; i--)
        {
            // pop the temps <= curr temp from stack
            while(!st.empty() && temperatures[st.top()] <= temperatures[i])
                st.pop();

            // store the diff between index at top of stack and curr index
            if(!st.empty())
                ans[i] = st.top() - i;

            // push the curr index in stack
            st.push(i);
        }

        return ans;
    }
};

// similar: [962. maximum-width-ramp]