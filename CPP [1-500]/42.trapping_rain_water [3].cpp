class Solution {
public:
    int trap(vector<int>& height) { //T.C.=O(n) , S.C.=O(n) , using stack
        int n=height.size();
        if(n < 3) //atleast 3 bars are required to trap water
            return 0;
        int water_sum=0;
        stack<int> st; //maintain stack in decreasing order, stores index instead of values
        for(int i=0; i<n; i++)
        {
            while(!st.empty() && height[i] > height[st.top()]) //while curr bar height > stack.top bar height
            {
                int popped= st.top(); //'popped' is bounded by height[st.top()] on the left and height[i] on the right
                st.pop();
                if(st.empty()) //no left bar exists
                    break;
                int width= i-st.top()-1; //distance between curr element, ie, right bar and stack.top element, ie, left bar
                int bounded_height= min(height[i], height[st.top()]) - height[popped];
                water_sum += width*bounded_height;
            }
            st.push(i);
        }
        return water_sum;
    }
};