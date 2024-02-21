class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) { // T.C.O(n), S.C.=O(n)
        int count = 0;
        unordered_set<string> s;
        for(string word: words)
        {
            string revWord = word;
            reverse(revWord.begin(), revWord.end());
            // reverse of curr word found in set
            if(s.find(revWord) != s.end())
                count++;
            // insert the curr word in set
            else
                s.insert(word);
        }
        return count;
    }
};