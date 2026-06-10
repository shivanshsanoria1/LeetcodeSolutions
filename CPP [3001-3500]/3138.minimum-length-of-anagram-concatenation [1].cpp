class Solution {
private:
    // returns all factors of n in increasing order
    vector<int> findAllFactors(int n){
        vector<int> factors;
        vector<int> factors2;

        for(int i=1; i*i<=n; i++)
            if(n % i == 0)
            {
                factors.push_back(i);
                if(i != n/i)
                    factors2.push_back(n/i);
            }
        
        for(int i=factors2.size()-1; i>=0; i--)
            factors.push_back(factors2[i]);

        return factors;
    }

    // returns true if s1 and s2 are anagrams
    bool isAnagram(string& s1, string& s2){
        vector<int> freq(26, 0);

        for(char ch: s1)
            freq[ch - 'a']++;
        
        for(char ch: s2)
        {
            freq[ch - 'a']--;
            if(freq[ch - 'a'] < 0)
                return false;
        }

        return true;
    }

public:
    // T.C.=O(n*sqrt(n)), S.C.=O(n)
    int minAnagramLength(string s) {
        int n=s.length();
        vector<int> factors = findAllFactors(n);

        for(int f: factors)
        {
            string t1 = s.substr(0, f);
            bool found = true;

            for(int i=f; i<n; i+=f)
            {
                string t2 = s.substr(i, f);

                if(!isAnagram(t1, t2))
                {
                    found = false;
                    break;
                }
            }
            
            if(found)
                return f;
        }

        return -1;
    }
};
/*
# n: length of string s
# length of string t must be a factor of n, lets say f
# any anagram of string t of length f must be repeated n/f times 
  to get the original string s of length n

# find all factors of n in increasing order
# check if every substring of length f is an anagram of each other
# if yes, then return that factor f
*/