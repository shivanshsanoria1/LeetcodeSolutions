class Solution {
private:
    vector<string> tokenize(string& s){
        vector<string> words;
        string word = "";
        s += ' ';
        for(char ch: s)
        {
            if(ch == ' ')
            {
                words.push_back(word);
                word = "";
            }
            else
                word += ch;
        }
        s.pop_back();

        return words;
    }

    // return true if words2[] can be made by the 
    // concatenation of some prefix and suffix of words1[]
    bool areSimilar(vector<string>& words1, vector<string>& words2){
        int n1 = words1.size(), n2 = words2.size();

        // find the longest-common-prefix of words1[] and words2[]
        int prefixIdx = -1;
        for(int i=0; i<n2; i++)
        {
            if(words1[i] == words2[i])
                prefixIdx = i;
            else
                break;
        }

        // find the longest-common-suffix of words1[] and words2[]
        // (excluding the already found prefix)
        int suffixIdx = n2;
        for(int i = n2-1; i > prefixIdx; i--)
        {
            if(words1[i + n1-n2] == words2[i])
                suffixIdx = i;
            else
                break;
        }

        return prefixIdx + 1 == suffixIdx;
    }

public:
    // T.C.=O(n1 + n2), S.C.=O(n1 + n2)
    // n1, n2: length of sentence1, sentence2
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> words1 = tokenize(sentence1);
        vector<string> words2 = tokenize(sentence2);

        return words1.size() > words2.size() ? areSimilar(words1, words2) : areSimilar(words2, words1);
    }
};