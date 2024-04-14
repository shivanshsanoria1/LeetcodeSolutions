class Solution {
public:
    // T.C.=O(n), S.C.=O(n) 
    // Monotonic (decreasing) stack
    int trap(vector<int>& height) { 
        int n=height.size();
        // atleast 3 bars are required to trap water
        if(n < 3) 
            return 0;

        int waterSum = 0;
        // stores index instead of values
        stack<int> st; 

        for(int i=0; i<n; i++)
        {
            // pop out the bars smaller than the curr-bar from stack
            while(!st.empty() && height[st.top()] < height[i]) 
            {
                // 'popped' is bounded by height[st.top()] on the left and height[i] on the right
                int popped = st.top(); 
                st.pop();

                // no left bar exists
                if(st.empty()) 
                    break;

                // distance between curr element (right bar) and stack.top element (left bar)
                int width = i - st.top() - 1; 
                int boundedHeight = min(height[i], height[st.top()]) - height[popped];

                waterSum += width * boundedHeight;
            }
            
            // add the curr bar in stack
            st.push(i);
        }

        return waterSum;
    }
};