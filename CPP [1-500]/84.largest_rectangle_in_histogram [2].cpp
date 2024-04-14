class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    // Monotonic (increasing / non-decreasing) stack + 1 vector
    int largestRectangleArea(vector<int>& heights) { 
        int n=heights.size();

        vector<int> left(n); 
        stack<int> st;

        // push the first index into stack
        st.push(0); 
        // for the 0th index, the leftmost index is itself
        left[0] = 0; 

        // find the left index limit of each element 
        for(int i=1; i<n; i++) 
        {
            // from the left side, remove the bars with height >= curr bar, from stack
            while(!st.empty() && heights[st.top()] >= heights[i]) 
                st.pop();
            
            left[i] = !st.empty() ? st.top() + 1 : 0;

            st.push(i);
        }

        // clear the stack
        while(!st.empty()) 
            st.pop();
        
        // push the last index in stack
        st.push(n-1); 
        // check for the last index
        int maxArea = heights[n-1] * (n-1 - left[n-1] + 1);

        // find the right index limit of each element 
        for(int i=n-2; i>=0; i--) 
        {
            // from the right side, remove the bars with height >= current bar, from stack
            while(!st.empty() && heights[st.top()] >= heights[i]) 
                st.pop();

            int right = !st.empty() ? st.top() - 1 : n-1;

            st.push(i);

            int width = right - left[i] + 1;
            maxArea = max(maxArea, heights[i] * width);
        }
        
        return maxArea;
    }
};
/*
# left[i]: upto which index on the left the bars have height >= curr bar height, ie, height[i]
# right[i]: upto which index on the right the bars have height >= curr bar height, ie, height[i]
# stack contains indexes (not elements)
*/