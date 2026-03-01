#include <iostream>
#include <string>
#include <vector>

using namespace std;

class RabinKarp{
private:
    string s1;
    
    // prime num to limit the hash-val
    const int MOD = int(1e9) + 7;
    // prime base to calculate hash
    // BASE should be a prime > max-distinct chars allowed in string (62)
    const int BASE = 67;

    // 'a'=1, 'b'=2, ..., 'z'=26
    // 'A'=27, 'B'=28, ..., 'Z'=52
    // '0'= 53, '1'=54, ..., '9'=62
    int getCharVal(const char ch){
        if(ch >= 'a' && ch <= 'z')
            return ch - 'a' + 1;
        if(ch >= 'A' && ch <= 'Z')
            return 26 + ch - 'A' + 1;
        if(ch >= '0' && ch <= '9')
            return 52 + ch - '0' + 1;
        
        return 0;
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
    RabinKarp(const string& s1){
        this->s1 = s1;
    };
    
    // T.C.=O(n1 + n2) Best/Avg, O(n1 * n2) Worst
    // S.C.=O(1)
    // returns the index of first occurence of s2 in s1 or -1 otherwise
    int findPattern(const string& s2) { 
        const int n1 = s1.length(), n2 = s2.length();
        // s2 cannot not be longer than s1
        if(n1 < n2) 
            return -1;
        // empty string is always found at index 0 in s1
        if(n2 == 0)
            return 0;

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

int main(){
    const string text = "sad3bUtsad";
    RabinKarp rk(text);
    
    const vector<string> patterns = {
        "sad3",
        "bUtsa",
        "dbUta"
    };
    
    cout<<"Text = \""<<text<<"\""<<endl;
    
    for(const string& pattern: patterns){
        int idx = rk.findPattern(pattern);
        
        if(idx == -1)
            cout<<"\""<<pattern<<"\" not found"<<endl;
        else
            cout<<"\""<<pattern<<"\" found at index "<<idx<<endl;
    }
    
    cout<<string(30, '-')<<endl;
    
    return 0;
}