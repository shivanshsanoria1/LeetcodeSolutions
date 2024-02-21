class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) { //T.C.=O(n1+n2) , S.C.=O(n2)
        int n1=nums1.size(), n2=nums2.size();
        vector<int> ans(n1);
        stack<int> st;
        unordered_map<int,int> mp; //stores NGE of all elements in nums2
        for(int i=0; i<n2; i++)
        {
            while(!st.empty() && nums2[i] > st.top()) //keep popping elements while curr element > stack top
            { //or stack becomes empty, add the {popped element, curr element} in map 
                mp[st.top()]= nums2[i];
                st.pop();
            }
            st.push(nums2[i]); //push the curr element in stack
        }
        while(!st.empty()) //elements remaining in stack do not have any NGE 
        {
            mp[st.top()]= -1;
            st.pop();
        }
        for(int i=0; i<n1; i++) //find the NGE of corresponding element of nums1[i] in nums2[] from the map 
            ans[i]= mp[nums1[i]];
        return ans;
    }
};