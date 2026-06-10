class Solution {
public:
    bool isVowel(char ch){
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    string sortVowels(string s) {
        int n=s.length();
        string ans = "";
        vector<int> lowerVowels(26, 0);
        vector<int> upperVowels(26, 0);

        for(int i=0; i<n; i++)
        {
            if(!isVowel(s[i]))
            {
                ans += s[i];
                continue; 
            }
            ans += '#';
            if(islower(s[i]))
                lowerVowels[s[i] - 'a']++;
            else
                upperVowels[s[i] - 'A']++;
        }

        int j = 0;
        for(int i=0; i<26; i++)
            while(upperVowels[i]--)
            {
                while(ans[j] != '#')
                    j++;
                ans[j] = i + 'A';
            }
        for(int i=0; i<26; i++)
            while(lowerVowels[i]--)
            {
                while(ans[j] != '#')
                    j++;
                ans[j] = i + 'a';
            }

        return ans;
    }
};