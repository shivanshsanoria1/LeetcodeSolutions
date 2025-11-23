class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    vector<int> nextGreaterElements(vector<int>& nums) { 
        int n=nums.size();
        // stores values instead of indexes
        stack<int> st;
        // iterate the array in reverse and push the elements in stack
        for(int i=n-1; i>=0; i--)
            st.push(nums[i]);

        vector<int> nge(n, -1);
        for(int i=n-1; i>=0; i--)
        {
            while(!st.empty() && nums[i] >= st.top())
                st.pop();

            nge[i] = st.empty() ? -1 : st.top();
            st.push(nums[i]);
        }

        return nge;
    }
};