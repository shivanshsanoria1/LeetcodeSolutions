class Solution {
public:
    // T.C.=O(n1 + n2), S.C.=O(26)
    bool isAnagram(string s, string t) {
        int n1=s.length(), n2=t.length();
        if(n1 != n2)
            return false;
        vector<int> freq(26, 0);
        for(int i=0; i<n1; i++) 
        {
            // increment the freq of corresponding char of string s
            freq[s[i] - 'a']++; 
            // decrement the freq of corresponding char of string t
            freq[t[i] - 'a']--; 
        }
        for(int i=0; i<26; i++) // check if freq are 0's
            if(freq[i] != 0)
                return false;
        return true;
    }
};