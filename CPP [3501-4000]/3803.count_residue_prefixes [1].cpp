class Solution {
public:
    // T.C.=O(n + 26), S.C.=O(26)
    int residuePrefixes(string s) {
        vector<bool> isFound(26, false);
        int distinctCount = 0;
        int residueCount = 0;
        for(int i=0; i<s.length(); i++){
            if(!isFound[s[i] - 'a']){
                isFound[s[i] - 'a'] = true;
                distinctCount++;
            }

            if(distinctCount == (i+1) % 3)
                residueCount++;
        }

        return residueCount;
    }
};