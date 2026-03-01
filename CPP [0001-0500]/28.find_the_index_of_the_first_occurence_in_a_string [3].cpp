class Solution {
private:
    // prime num to limit the hash-val
    const int MOD = int(1e9) + 7;
    // prime base to calculate hash
    // BASE should be a prime > max-distinct chars allowed in string (26)
    const int BASE = 31;

    // a=1, b=2, c=3, ..., z=26
    int getCharVal(const char ch){
        return ch - 'a' + 1;
    }

    // generates the hash-val of prefix of 's' of length 'len'
    int generateInitialHash(const string& s, const int len){
        int hash = 0;
        for(int i=0; i<len; i++)
            hash = (1LL * hash * BASE + getCharVal(s[i])) % MOD;

        return hash;
    }

    // max base value multiplied to a char in a hash
    int calculateBasePow(const int n){
        int basePow = 1;
        for(int i=1; i<n; i++)
            basePow = (1LL * basePow * BASE) % MOD;

        return basePow;
    }

    // update the hash by removing the Most-Significant-char (msc)
    // and adding a new Least-Significant-char (lsc)
    int updateHash(int hash, const char msc, const char lsc, const int basePow){ 
        // actual val of MSC in hash
        int mscVal = (1LL * getCharVal(msc) * basePow) % MOD;

        // remove the MSC
        hash = (hash - mscVal + MOD) % MOD;
        // left-shift the hash by BASE
        hash = (1LL * hash * BASE) % MOD;
        // add the new LSC
        hash = (hash + getCharVal(lsc)) % MOD;

        return hash;
    }

    // returns true if substring of s1 starting at 
    // index 'start' and of length 'len' matches with s2
    bool areMatching(const string& s1, const int start, const int len, const string& s2){
        for(int i = start; i < start + len; i++)
            if(s1[i] != s2[i - start])
                return false;

        return true;
    }

public:
    // T.C.=O(n1 * n2), S.C.=O(1)
    // Rabin-Karp algo. / Rolling-hash
    int strStr(string haystack, string needle) { 
        // rename the parameters
        const string& s1 = haystack;
        const string& s2 = needle;

        const int n1 = s1.length(), n2 = s2.length();
        // s2 cannot not be longer than s1
        if(n1 < n2) 
            return -1;

        // hash of s1 in index-range [0, n2-1]
        int hash1 = generateInitialHash(s1, n2);
        // hash of s2
        const int hash2 = generateInitialHash(s2, n2);
        
        if(hash1 == hash2 && areMatching(s1, 0, n2, s2))
            return 0;

		int basePow = calculateBasePow(n2);

        for(int i=1; i <= n1-n2; i++){
            hash1 = updateHash(hash1, s1[i-1], s1[i-1+n2], basePow);

            if(hash1 == hash2 && areMatching(s1, i, n2, s2))
                return i;
        }

        // s2 not found in s1
        return -1;
    }
};