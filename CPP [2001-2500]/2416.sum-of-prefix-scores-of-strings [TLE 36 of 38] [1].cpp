class Solution {
public:
    // T.C.=O(n*m^2), S.C.=O(n*m^2)
    // n: size of words[], m: max-length of a word in words[]
    vector<int> sumPrefixScores(vector<string>& words) {
        // prefix -> freq
        unordered_map<string, int> mp;
        for(string& word: words)
        {
            string prefix = "";
            for(char ch: word)
            {
                prefix += ch;
                mp[prefix]++;
            }
        }

        vector<int> scores;
        for(string& word: words)
        {
            string prefix = "";
            int score = 0;
            for(char ch: word)
            {
                prefix += ch;
                score += mp[prefix];
            }

            scores.push_back(score);
        }

        return scores;
    }
};