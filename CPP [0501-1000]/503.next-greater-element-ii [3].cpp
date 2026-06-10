class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    // Monotonic-Stack (decreasing)
    vector<int> nextGreaterElements(vector<int>& nums) { 
        int n=nums.size();
        // nums2[] is nums[] concatenated 2 times
        vector<int> nums2(2*n);
        for(int i=0; i<n; i++)
        {
            nums2[i] = nums[i];
            nums2[i+n] = nums[i];
        }

        // stores indexes instead of values
        stack<int> st; 
        vector<int> nge(n, -1);
        
        for(int i=0; i<2*n; i++)
        {
            while(!st.empty() && nums2[st.top()] < nums2[i]) 
            {
                if(st.top() >= n)
                    st.top() -= n;

                nge[st.top()] = nums2[i]; 
                st.pop();
            }

            st.push(i);
        }

        return nge;
    }
};