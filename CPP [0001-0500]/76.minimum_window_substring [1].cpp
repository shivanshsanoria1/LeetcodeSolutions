class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        for(auto it:t) //add all char. of string t into a map
            mp[it]++;
        int left=0, right=0;
        int count=mp.size(); //num of unique letters in string t
        int min_len=INT_MAX, start_index=0; //min length of substring, starting index of that substring
        while(right < s.length())
        {
            if(mp.find(s[right]) != mp.end()) //s[right] found in map
            {
                mp[s[right]]--; //decrement the key of s[right]
                if(mp[s[right]]==0)
                    count--;  
            }
            while(count==0) //while a valid substring is found
            {
                if(right-left+1 < min_len) //curr window size < min length
                {
                    min_len=right-left+1;
                    start_index=left; //save the starting index of curr window
                }
                if(mp.find(s[left]) != mp.end()) //s[left] found in map
                {
                    mp[s[left]]++; //increment the key of s[left]
                    if(mp[s[left]]==1)
                        count++;
                }
                left++;
            }
            right++;
        }
        return min_len==INT_MAX ? "" : s.substr(start_index, min_len);
    }
};