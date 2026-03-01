class Solution {
private:
    bool isVowel(const char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

public:
    // T.C.=O(n), S.C.=O(1)
    string trimTrailingVowels(string s) {
        for(int i=s.length()-1; i>=0; i--){
            if(isVowel(s[i]))
                s.pop_back();
            else
                break;
        }
        
        return s;
    }
};