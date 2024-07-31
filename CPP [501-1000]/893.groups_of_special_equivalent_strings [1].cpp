class Solution {
private:
    string getHash(string& s){
        string even = "";
        string odd = "";

        for(int i=0; i<s.length(); i++)
        {
            if(i % 2 == 0)
                even += s[i];
            else
                odd += s[i];
        }

        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end());

        return even + odd;
    }

public:
    // T.C.=O(n*m*log(m)), S.C.=O(n*m)
    // n: size of words[], m: max length of a word in words[]
    int numSpecialEquivGroups(vector<string>& words) {
        unordered_set<string> hashes;
        for(string& word: words)
            hashes.insert(getHash(word));

        return hashes.size();
    }
};