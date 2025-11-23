class Solution {
public:
    // T.C.=O(n1 + (n2 - n1)*26), S.C.=O(26)
    // fixed-length sliding-window
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();
        // s1 cannot be a substring of s2 if it is longer than s2
        if(n1 > n2) 
            return false;

        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        // note the freq of the first n1 chars of s1 and s2
        for(int i=0; i<n1; i++)
        {
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }
        
        // check the first window
        if(freq1 == freq2)
            return true;
        
        int left = 0, right = n1;
        while(right < n2)
        {
            freq2[s2[left] - 'a']--;
            left++;

            freq2[s2[right] - 'a']++;
            right++;

            if(freq1 == freq2)
                return true;
        }

        return false;
    }
};

// similar: [438. find-all-anagrams-in-a-string]