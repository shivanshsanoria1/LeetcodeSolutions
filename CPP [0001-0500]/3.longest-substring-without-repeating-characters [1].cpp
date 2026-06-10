class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length(), left=0, right=0, max_sub=0;
        set<int> st;
        while(right<n)
        {
            if(st.count(s[right])==0) // s[right] is not present in set
            {
                st.insert(s[right]); // insert s[right] to set
                max_sub = max(max_sub,right-left+1); // keep track of max length of substring 
                right++;
            }
            else // s[right] is present in set
            {
                st.erase(s[left]); // remove s[left] from set
                left++;
            }
        }
        return max_sub;
    }
};