class Solution {
public:
    void nextGreaterElement(vector<int>& nums, vector<bool>& greater) //maintain the stack in decreasing order
    {
        int n= nums.size();
        stack<int> st; //stack contains indexes and not values
        for(int i=0; i<n; i++)
        {
            while(!st.empty() && nums[i] > nums[st.top()]) //curr element is greater than element at stack.top
            {
                greater[st.top()]=true; //mark the index stack.top in greater[]
                st.pop();
            }
            st.push(i);
        }
    }
    
    void prevSmallerElement(vector<int>& nums, vector<bool>& smaller) //maintain the stack in increasing order
    {
        int n= nums.size();
        stack<int> st; //stack contains indexes and not values
        for(int i=n-1; i>=0; i--)
        {
            while(!st.empty() && nums[i] < nums[st.top()]) //curr element is smaller than element at stack.top
            {
                smaller[st.top()]=true; //mark the index stack.top in smaller[]
                st.pop();
            }
            st.push(i);
        }
    }
    
    bool increasingTriplet(vector<int>& nums) { //T.C.=O(n) , S.C.=O(n)
        int n= nums.size();
        if(n < 3) //atleast 3 numbers are needed
            return false;
        vector<bool> greater(n,false); //to store nextGreaterElement
        vector<bool> smaller(n,false); //to store prevSmallerElement
        nextGreaterElement(nums,greater);
        prevSmallerElement(nums,smaller);
        for(int i=0; i<n; i++)
            if(greater[i]==true && smaller[i]==true) //both nextGreaterElement and prevSmallerElement exists
                return true;
        return false;
    }
};