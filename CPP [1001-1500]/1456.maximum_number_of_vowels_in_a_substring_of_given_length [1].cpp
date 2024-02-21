class Solution {
public:
    bool isVowel(char c)
    {
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
            return true;
        return false;
    }

    int maxVowels(string s, int k) {
        int n = s.length();
        int currCount = 0;
        // substring of length k starting at index 0
        for(int i=0; i<k; i++)
            if(isVowel(s[i]))
                currCount++;
        int ans = currCount;
        // substrings of length k starting at index 1,2,3,...
        for(int i=1; i+k-1 < n; i++)
        {
            if(isVowel(s[i-1]))
                currCount--;
            if(isVowel(s[i+k-1]))
                currCount++;
            ans = max(ans, currCount);
        }
        return ans;
    }
};