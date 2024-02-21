class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mp1; //char in s -> char in t
        unordered_map<char,char> mp2; //char in t -> char in s
        for(int i=0; i<s.length(); i++)
        {
            if(mp1.find(s[i]) != mp1.end()) //s[i] present in map
            {
                if(mp1[s[i]] != t[i]) //check if the new partner of s[i] ,ie, t[i] 
                    return false;    //is equal to its old partner ,ie, mp[s[i]]
            }
            else
                mp1[s[i]]=t[i]; //add s[i] and its partner t[i] in map
            
            if(mp2.find(t[i]) != mp2.end()) //t[i] present in map
            {
                if(mp2[t[i]] != s[i]) //check if the new partner of t[i] ,ie, s[i] 
                    return false;    //is equal to its old partner ,ie, mp[t[i]]
            }
            else
                mp2[t[i]]=s[i]; //add t[i] and its partner s[i] in map
        }
        return true;
    }
};