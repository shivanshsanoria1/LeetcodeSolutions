class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    string largestEven(string s) {
        int idx = -1;
        for(int i=s.length()-1; i>=0; i--)
            if(s[i] == '2'){
                idx = i;
                break;
            }
        
        return s.substr(0, idx + 1);
    }
};