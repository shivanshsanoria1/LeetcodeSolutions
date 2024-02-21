class Solution {
public:
    string customSortString(string order, string s) { 
        vector<int> freq(26, 0);
        for(char ch: s)
            freq[ch - 'a']++;
        string ans = "";
        // add all occurences of chars of 's' in 'ans' as they appear in 'order'
        for(char ch: order)
            if(freq[ch - 'a'] > 0)
                while(freq[ch - 'a']--)
                    ans += ch;
        // add all occurences of remaining chars of 's' in 'ans'
        for(int i=0; i< 26; i++)
            if(freq[i] > 0)
                while(freq[i]--)
                    ans += char(i + 'a');
        return ans;
    }
};