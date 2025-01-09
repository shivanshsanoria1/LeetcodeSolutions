class Solution {
private:
    // returns true if s1 is both a prefix and suffix of s2
    bool isPrefixAndSuffix(string& s1, string& s2){
        int n1 = s1.length(), n2 = s2.length();
        
        // s1 cannot be longer than s2
        if(n1 > n2)
            return false;
        
        return s2.substr(0, n1) == s1 && s2.substr(n2-n1) == s1;
    }

public:
    // T.C.=O(n^2 * m), S.C.=O(m)
    // n: size of words[], m: max-length of string in words[]
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int count = 0;

        for(int i=0; i<n-1; i++)
            for(int j=i+1; j<n; j++)
                if(isPrefixAndSuffix(words[i], words[j]))
                    count++;

        return count;
    }
};