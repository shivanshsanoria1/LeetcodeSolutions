class Solution {
public:
    // T.C.=O(n1 + n2), S.C.=O(26)
    bool isAnagram(string s, string t) {
        int n1=s.length(), n2=t.length();
        if(n1 != n2)
            return false;
        unordered_map<char, int> mp; // char -> freq
        for(int i=0; i<n1; i++)
        {
            mp[s[i]]++;
            mp[t[i]]--;
        }
        for(auto it: mp)
            if(it.second != 0)
                return false;
        return true;
    }
};