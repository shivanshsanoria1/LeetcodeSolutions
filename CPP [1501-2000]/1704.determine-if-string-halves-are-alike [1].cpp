class Solution {
private:
    bool isVowel(char ch){
        ch = tolower(ch);

        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

public:
    // T.C.=O(n), S.C.=O(1)
    bool halvesAreAlike(string s) {
        int n=s.length();

        int leftVowelCount = 0;
        for(int i=0; i<n/2; i++)
            if(isVowel(s[i]))
                leftVowelCount++;
        
        int rightVowelCount = 0;
        for(int i=n/2; i<n; i++)
            if(isVowel(s[i]))
                rightVowelCount++;

        return leftVowelCount == rightVowelCount;
    }
};