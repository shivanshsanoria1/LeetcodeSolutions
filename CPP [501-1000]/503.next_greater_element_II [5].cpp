class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) { //T.C.=O(n) , S.C.=O(n)
        int n=nums.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=n-1; i>=0; i--) //iterate the array in reverse and push the elements in stack
            st.push(nums[i]);
        for(int i=n-1; i>=0; i--)
        {
            while(!st.empty() && nums[i] >= st.top()) //pop the elements from stack until stack.top > curr
                st.pop();
            if(st.empty()) //if stack becomes empty then no NGE exists
                ans[i]= -1;
            else //NGE is at stack.top
                ans[i]= st.top();
            st.push(nums[i]); //push curr element in stack
        }
        return ans;
    }
};