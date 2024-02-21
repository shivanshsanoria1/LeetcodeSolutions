class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) { // T.C.=O(n), S.C.=O(n)
        int n=temperatures.size();
        // maintain the stack in strictly decreasing order of temperatures
        stack<int> st; // stores indexes not values
        vector<int> ans(n, 0);
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