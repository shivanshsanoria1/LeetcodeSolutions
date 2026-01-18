class Solution {
private:
    bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

public:
    // T.C.=O(n), S.C.=O(1)
    int vowelConsonantScore(string s) {
        int v = 0, c = 0;
        for(char ch: s){
            if(ch < 'a' || ch > 'z')
                continue;
            
            if(isVowel(ch))
                v++;
            else
                c++;
        }

        return c == 0 ? 0 : v/c;
    }
};