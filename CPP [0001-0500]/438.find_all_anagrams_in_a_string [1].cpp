class Solution {
public:
    // T.C.=O((n1 - n2) * (n2 + 26)), S.C.=O(26)
    vector<int> findAnagrams(string s, string p) {
        int n1 = s.length(), n2 = p.length();
        // p cannot be a substring of s if it is longer than s
        if(n1 < n2) 
            return {};

        vector<int> freq2(26, 0);
        for(char ch: p)
            freq2[ch - 'a']++;

        vector<int> ans;
        for(int i=0; i <= n1-n2; i++)
        {
            vector<int> freq1(26, 0);
            for(int j=i; j<i+n2; j++)
                freq1[s[j] - 'a']++;
            
            if(freq1 == freq2)
                ans.push_back(i);
        }
        
        return ans;
    }
};

// similar: [567. permutation-in-string]