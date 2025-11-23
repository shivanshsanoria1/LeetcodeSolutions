class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    // Monotonic (increasing / non-decreasing) stack 
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int maxArea = 0;
        // stack contains indexes (not elements)
        stack<int> st; 

        for(int i=0; i<=n; i++)
        {
            // assume the curr height to be zero for the index after the last index
            int currHeight = i == n ? 0 : heights[i]; 

            // remove all the bars with height > curr bar height from stack
            while(!st.empty() && heights[st.top()] > currHeight) 
            {
                int popped = st.top();
                st.pop();

                int width = !st.empty() ? (i - st.top() - 1) : i;

                maxArea = max(maxArea, heights[popped] * width);
            }
            
            st.push(i);
        }

        return maxArea;
    }
};