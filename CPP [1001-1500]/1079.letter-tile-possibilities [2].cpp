class Solution {
public:
    int solve(string& s, vector<int>& freq)
    {
        int sum=0;
        for(int i=0; i<26; i++)
            if(freq[i] > 0)
            {
                freq[i]--;
                s += (i+'A');
                sum += solve(s,freq);
                s.pop_back();
                freq[i]++;
            }
        return 1 + sum;
    }
    
    int numTilePossibilities(string tiles) {
        vector<int> freq(26,0);
        for(int i=0; i<tiles.length(); i++)
            freq[tiles[i]-'A']++;
        string s="";
        return solve(s,freq) - 1;
    }
};