class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) { //T.C.=O(n) , S.C.=O(n)
        int n=nums.size();
        vector<int> ans(n,-1);
        stack<int> st; //stores index of elements instead of values
        for(int i=0; i<2*n; i++)
        {
            int index= i % n;
            while(!st.empty() && nums[index] > nums[st.top()])
            {
                ans[st.top()]= nums[index];
                st.pop();
            }
            st.push(index);
        }
        return ans;
    }
};