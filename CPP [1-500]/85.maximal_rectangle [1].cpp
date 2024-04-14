class Solution {
private:
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

public:
    // T.C.=O(m*n), S.C.=O(n)
    int maximalRectangle(vector<vector<char>>& matrix) { 
        int m=matrix.size(), n=matrix[0].size();
        // to store histogram for each row
        vector<int> heights(n, 0); 

        int maxArea = 0;

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                // increment the histogram height
                if(matrix[i][j] == '1')
                    heights[j]++;
                // reset the histogram height
                else 
                    heights[j] = 0;
            }

            maxArea = max(maxArea, largestRectangleArea(heights));
        }

        return maxArea;
    }
};
// prerequisite: 84.[largest-rectangle-in-histogram]