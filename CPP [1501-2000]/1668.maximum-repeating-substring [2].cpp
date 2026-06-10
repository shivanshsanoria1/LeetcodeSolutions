class Solution {
public:
    int maxRepeating(string sequence, string word) {
        string wordKRep = word;
        int k = 0;
        while(sequence.find(wordKRep) != string::npos)
        {
            wordKRep += word;
            k++;
        }
        return k;
    }
};