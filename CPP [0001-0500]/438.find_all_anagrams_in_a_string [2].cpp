class Solution {
public:
    // T.C.=O(n2 + (n1 - n2)*26), S.C.=O(26)
    // fixed-length sliding-window
    vector<int> findAnagrams(string s, string p) {
        int n1 = s.length(), n2 = p.length();
        // p cannot be a substring of s if it is longer than s
        if(n1 < n2) 
            return {};

        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        // note the freq of the first n2 chars of s and p
        for(int i=0; i<n2; i++)
        {
            freq1[s[i] - 'a']++;
            freq2[p[i] - 'a']++;
        }
        
        vector<int> ans;
        // check the first window
        if(freq1 == freq2)
            ans.push_back(0);
        
        int left = 0, right = n2;
        while(right < n1)
        {
            freq1[s[left] - 'a']--;
            left++;

            freq1[s[right] - 'a']++;
            right++;

            if(freq1 == freq2)
                ans.push_back(left);
        }

        return ans;
    }
};

// similar: [567. permutation-in-string]