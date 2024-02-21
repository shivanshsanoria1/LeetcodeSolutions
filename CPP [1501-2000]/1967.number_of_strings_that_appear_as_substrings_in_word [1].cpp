class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int len=word.length();
        unordered_set<string> s; // to store all substrings of 'word'
        for(int i=0; i<len; i++)
        {
            string substr = "";
            for(int j=i; j<len; j++)
            {
                substr += word[j];
                s.insert(substr);
            }
        }
        int count = 0;
        for(string& pattern: patterns)
            if(s.find(pattern) != s.end()) // pattern found in set
                count++;
        return count;
    }
};