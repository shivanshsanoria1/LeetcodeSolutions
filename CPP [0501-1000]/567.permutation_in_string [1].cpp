class Solution {
public:
    // T.C.=O((n2 - n1) * (n1 + 26)), S.C.=O(26)
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();
        // s1 cannot be a substring of s2 if it is longer than s2
        if(n1 > n2) 
            return false;

        vector<int> freq1(26, 0);
        for(char ch: s1)
            freq1[ch -'a']++;

        for(int i=0; i <= n2-n1; i++)
        {
            vector<int> freq2(26, 0);
            for(int j=i; j<i+n1; j++)
                freq2[s2[j] - 'a']++;
            
            if(freq1 == freq2)
                return true;
        }
        
        return false;
    }
};

// similar: [438. find-all-anagrams-in-a-string]