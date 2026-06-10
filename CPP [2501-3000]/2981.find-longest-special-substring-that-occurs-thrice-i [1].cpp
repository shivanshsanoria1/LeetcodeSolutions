class Solution {
public:
    // T.C.=O(n^2), S.C.=O(n^2)
    int maximumLength(string s) {
        // substring -> freq
        unordered_map<string, int> mp;

        int n = s.length();
        for(int i=0; i<n; i++)
        {
            string sub = "";
            for(int j=i; j<n; j++)
            {
                sub += s[j];
                if(sub[0] != sub.back())
                    break;
                mp[sub]++;
            }
        }

        int maxLen = -1;
        for(auto& [sub, freq]: mp)
            if(freq >= 3)
                maxLen = max(maxLen, (int)sub.length());
        
        return maxLen;
    }
};