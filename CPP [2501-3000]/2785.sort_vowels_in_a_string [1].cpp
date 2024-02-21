class Solution {
public:
    bool isVowel(char ch){
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    string sortVowels(string s) {
        int n=s.length();
        string ans = "";
        string vowels = "";

        for(int i=0; i<n; i++)
        {
            if(!isVowel(s[i]))
                ans += s[i];
            else
            {
                ans += '#';
                vowels += s[i];
            }
        }

        sort(vowels.begin(), vowels.end());

        int j = 0;
        for(int i=0; i<n; i++)
        {
            if(ans[i] != '#')
                continue;
            ans[i] = vowels[j];
            j++;
        }
        
        return ans;
    }
};