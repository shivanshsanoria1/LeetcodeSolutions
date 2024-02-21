class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> s;
        for(char ch: allowed)
            s.insert(ch);
        int invalid=0;
        for(string str: words)
            for(char ch: str)
                if(s.find(ch) == s.end()) //char 'ch' is not present in set
                {
                    invalid++;
                    break;
                }
        return words.size()-invalid;
    }
};