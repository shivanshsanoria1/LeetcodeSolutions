class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) { //T.C.=O(n) , S.C.=O(n)
        int n=nums.size();
        vector<int> nums2(2*n); //nums2[] is nums[] concatenated 2 times
        vector<int> ans(n,-1);
        stack<int> st; //stores index of elements instead of values
        for(int i=0; i<n; i++)
        {
            nums2[i]= nums[i];
            nums2[i+n]= nums[i];
        }
        for(int i=0; i<2*n; i++)
        {
            int curr= nums2[i]; //curr acts as NGE to the value at index st.top() in nums2[] 
            while(!st.empty() && curr > nums2[st.top()]) //curr element > element at index stack.top
            {
                if(st.top() >= n) //if index at stack.top exceeds n then reduce it by n
                    st.top()= st.top()-n;
                ans[st.top()]= curr; //NGE for the element at index stack.top is found
                st.pop();
            }
            st.push(i); //push the curr index in stack
        }
        return ans;
    }
};