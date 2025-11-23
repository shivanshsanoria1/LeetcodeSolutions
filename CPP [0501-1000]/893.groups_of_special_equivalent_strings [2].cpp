class Solution {
private:
    string getHash(string& s){
        vector<int> freq_even(26, 0);
        vector<int> freq_odd(26, 0);

        for(int i=0; i<s.length(); i++)
        {
            if(i % 2 == 0)
                freq_even[s[i] - 'a']++;
            else
                freq_odd[s[i] - 'a']++;
        }

        string hash = "";
        
        for(int i=0; i<26; i++)
            hash += to_string(freq_even[i]) + "#";
        for(int i=0; i<26; i++)
            hash += to_string(freq_odd[i]) + "#";
        
        return hash;
    }

public:
    // T.C.=O(n*(m + 2*26)), S.C.=O(n*2*26)
    // n: size of words[], m: max length of a word in words[]
    int numSpecialEquivGroups(vector<string>& words) {
        unordered_set<string> hashes;
        for(string& word: words)
            hashes.insert(getHash(word));

        return hashes.size();
    }
};