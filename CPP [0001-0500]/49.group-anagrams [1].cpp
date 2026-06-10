class Solution {
private:
    bool isAnagram(string& s1, string& s2){
        int n1=s1.length(), n2=s2.length();
        // anagrams must be of equal length
        if(n1 != n2)
            return false;

        vector<int> freq(26, 0);
        for(int i=0; i<n1; i++)
        {
            // increment the freq of corresponding char of string s1
            freq[s1[i] - 'a']++; 
            // decrement the freq of corresponding char of string s1
            freq[s2[i] - 'a']--; 
        }

        for(int i=0; i<26; i++) 
            if(freq[i] != 0)
                return false;
        return true;
    }

public:
    // T.C.=O(n^2*l), S.C.=O(1)
    // n: legnth of strs[], l: max length of string in strs[]
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        vector<vector<string>> ans;
        // to check if the string is included in ans or not
        vector<bool> check(n, false); 
        for(int i=0; i<n; i++)
        {
            // string already included in ans
            if(check[i]) 
                continue;
            vector<string> anag;
            for(int j=i; j<n; j++)
                // string at index j is the anagram of string at index i
                if(isAnagram(strs[i], strs[j]))
                {
                    anag.push_back(strs[j]);
                    check[j] = true;
                }
            // only push the anagram vector if it is non empty
            if(!anag.empty()) 
                ans.push_back(anag);
        }
        return ans;
    }
};