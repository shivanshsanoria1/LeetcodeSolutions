class Solution {
public:
    // T.C.=O(n)
    // n: length of 's' and 't'
    bool isIsomorphic(string s, string t) {
        // char in s -> char in t
        unordered_map<char, char> mp1; 
        // char in t -> char in s
        unordered_map<char, char> mp2; 

        for(int i=0; i<s.length(); i++)
        {
            // s[i] not found in map so 
            // add s[i] and its partner t[i] in map
            if(mp1.find(s[i]) == mp1.end())
                mp1[s[i]] = t[i];
            // s[i] found in map so 
            // check if the curr partner of s[i], ie, t[i] 
            // is equal to its prev partner, ie, mp[s[i]]
            else if(mp1[s[i]] != t[i])
                return false;
            
            // t[i] not found in map so 
            // add t[i] and its partner s[i] in map
            if(mp2.find(t[i]) == mp2.end())
                mp2[t[i]] = s[i]; 
            // t[i] found in map so 
            // check if the curr partner of t[i], ie, s[i] 
            // is equal to its prev partner, ie, mp[t[i]]
            else if(mp2[t[i]] != s[i]) 
                return false;
        }

        return true;
    }
};