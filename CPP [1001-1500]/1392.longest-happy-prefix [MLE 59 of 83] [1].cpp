class Solution {
public:
    string longestPrefix(string s) {
        unordered_set<string> dict;
        int n=s.length();

        // add all the prefix in set
        string prefix = "";
        for(int i=0; i<n-1; i++)
        {
            prefix += s[i];
            dict.insert(prefix);
        }
        
        // generate all the suffix's (in decreasing order of length)
        // and check if its matching prefix is found in set
        for(int i=1; i<n; i++)
        {
            string suffix = s.substr(i);
            if(dict.find(suffix) != dict.end())
                return suffix;
        }

        return "";
    }
};