class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    string reverseByType(string s) {
        string alpha = "";
        string special = "";
        for(char ch: s){
            if(isalpha(ch))
                alpha += ch;
            else
                special += ch;
        }

        reverse(alpha.begin(), alpha.end());
        reverse(special.begin(), special.end());
        
        int i=0, j=0;
        for(char& ch: s)
            ch = isalpha(ch) ? alpha[i++] : special[j++];
            
        return s;
    }
};