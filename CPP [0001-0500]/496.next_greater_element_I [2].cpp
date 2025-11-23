class Solution {
public:
    // T.C.=O(n1 + n2), S.C.=O(n2)
    // Monotonic-Stack (decreasing)
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) { 
        // stores values and not indexes
        stack<int> st;
        // num -> NGE ; (for elements in nums2[])
        unordered_map<int, int> mp;

        for(int num: nums2)
        {
            // keep popping elements while stack top < curr element
            // add the {popped element, curr element} in map 
            while(!st.empty() && st.top() < num) 
            {
                mp[st.top()] = num;
                st.pop();
            }

            st.push(num);
        }

        // elements remaining in stack do not have any NGE 
        while(!st.empty()) 
        {
            mp[st.top()] = -1;
            st.pop();
        }
        
        vector<int> ans;
        for(int num: nums1) 
            ans.push_back(mp[num]);

        return ans;
    }
};