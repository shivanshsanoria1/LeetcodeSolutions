class Solution {
public:
    // T.C.=O(n1*n2), S.C.=O(26)
    // Rabin-Karp algo. / Rolling-hash
    int strStr(string haystack, string needle) { 
        int n1=haystack.length(), n2=needle.length();
        // s2 cannot not be longer than s1
        if(n1 < n2) 
            return -1;

        // chars a,b,c,...,z are assigned 
        // values 1,2,3,...,26 respectively
        vector<int> values(26, 0);
        for(int i=0; i<26; i++)
            values[i] = i+1;

        // hash of s2
        int hash2 = 0;
        for(char ch: needle)
            hash2 += values[ch - 'a'];
        
        // hash of substring of s1 starting 
        // at index 0 and of length n2
        int hash1 = 0;
        for(int i=0; i<n2; i++)
            hash1 += values[haystack[i] - 'a'];
        
        if(hash1 == hash2 && haystack.substr(0, n2) == needle)
            return 0;

        int left = 1, right = n2;
        while(right < n1)
        {
            hash1 -= values[haystack[left - 1] - 'a'];
            hash1 += values[haystack[right] - 'a'];

            if(hash1 == hash2 && haystack.substr(left, n2) == needle)
                return left;
            
            left++;
            right++;
        }

        // s2 not found in s1
        return -1;
    }
};
// s1: haystack, s2: needle