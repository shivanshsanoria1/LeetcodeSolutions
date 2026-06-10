class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length(), left=0, right=0, max_sub=0;
        vector<bool> count(256,false); // vector of size 256 with all elements as false
        while(right < n)
        {
            if(count[s[right]] == false) // s[right] is not present in array
            {
                count[s[right]]=true; // update the count of s[right] = true
                max_sub = max(max_sub,right-left+1); // keep track of max length of substring 
                right++;
            }
            else // s[right] is present in array
            {
                count[s[left]]=false; // update the count of s[left] = false
                left++;
            }
        }
        return max_sub;
    }
};