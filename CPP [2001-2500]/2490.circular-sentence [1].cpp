class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    bool isCircularSentence(string sentence) {
        int n = sentence.length();

        if(sentence[0] != sentence[n-1])
            return false;

        for(int i=0; i<n; i++)
            if(sentence[i] == ' ' && sentence[i-1] != sentence[i+1])
                return false;

        return true;
    }
};