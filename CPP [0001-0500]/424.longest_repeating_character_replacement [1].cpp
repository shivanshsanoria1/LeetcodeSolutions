class Solution {
public:
    int characterReplacement(string s, int k) { //sliding window technique
        unordered_map<char,int> mp;
        int left=0, right=0;
        int window_size, max_freq=0, max_len;
        while(right < s.length())
        {
            mp[s[right]]++; //increment freq of s[right] in map
            max_freq = max(max_freq,mp[s[right]]); //update max freq present in map
            window_size=right-left+1;
            if(window_size-max_freq <= k) //if atmost k replacements are possible in curr window
                max_len=window_size;
            while(window_size-max_freq > k) //while atmost k replacements are not possible in curr window
            {
                mp[s[left]]--; //decrement the freq of s[left] from map
                max_freq = max(max_freq,mp[s[left]]); //update max freq present in map
                left++;
                window_size--;
            }
            right++;
        }
        return max_len;
    }
};