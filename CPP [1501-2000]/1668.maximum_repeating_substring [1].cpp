class Solution {
public:
    int maxRepeating(string sequence, string word) {
        string wordKRep = "";
        int k = 0;
        int ans = 0;
        while(wordKRep.length() <= sequence.length())
        {
            // 'wordKRep' is a substring of 'sequence'
            if(sequence.find(wordKRep) != string::npos) 
                ans = k;
            wordKRep += word;
            k++;
        }
        return ans;
    }
};