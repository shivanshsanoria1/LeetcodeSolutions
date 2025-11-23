class Solution {
private:
    string convertToLowercase(string& s){
        string lower = "";
        for(char ch: s)
            lower += tolower(ch);

        return lower;
    }

    bool isVowel(char ch){
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'; 
    }

    // replace each vowel with wildcard '*'
    string convertToWildcard(string& s){
        string wildcard = "";
        for(char ch: s)
            wildcard += isVowel(ch) ? '*' : ch;

        return wildcard;
    }

public:
    // T.C.=O(n + q), S.C.=O(n)
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        // exact words as found in wordlist[]
        unordered_set<string> dict;
        // lowercase word -> first matching word in wordlist[]
        unordered_map<string, string> mp1;
        // lowercase wildcard word -> first matching word in wordlist[]
        unordered_map<string, string> mp2;

        for(string& word: wordlist)
        {
            dict.insert(word);
            
            string lower = convertToLowercase(word);
            if(mp1.find(lower) == mp1.end())
                mp1[lower] = word;
            
            string wildcard = convertToWildcard(lower);
            if(mp2.find(wildcard) == mp2.end())
                mp2[wildcard] = word;
        }
        
        vector<string> ans;
        for(string& query: queries)
        {
            if(dict.find(query) != dict.end())
            {
                ans.push_back(query);
                continue;
            }

            string lower = convertToLowercase(query);
            if(mp1.find(lower) != mp1.end())
            {
                ans.push_back(mp1[lower]);
                continue;
            }

            string wildcard = convertToWildcard(lower);
            if(mp2.find(wildcard) != mp2.end())
            {
                ans.push_back(mp2[wildcard]);
                continue;
            }

            ans.push_back("");
        }

        return ans;
    }
};