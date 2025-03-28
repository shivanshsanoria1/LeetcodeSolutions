class Solution {
private:
    // returns true if s1 is both a prefix and suffix of s2
    bool isPrefixAndSuffix(string& s1, string& s2){
        int n1 = s1.length(), n2 = s2.length();
        
        // s1 cannot be longer than s2
        if(n1 > n2)
            return false;

        // check if s1 is prefix of s2
        for(int i=0; i<n1; i++)
            if(s1[i] != s2[i])
                return false;

        // check if s1 is suffix of s2
        for(int i=0; i<n1; i++)
            if(s1[i] != s2[i + n2 - n1])
                return false;
        
        return true;
    }

public:
    // T.C.=O(n^2 * m), S.C.=O(1)
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