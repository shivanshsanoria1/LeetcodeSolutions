class Solution {
public:
    int count=0;
    void solve(string& s, vector<int>& freq)
    {
        for(int i=0; i<26; i++)
            if(freq[i] > 0)
            {
                freq[i]--; //decrement the freq of curr char
                s += (i+'A'); //add the curr char to the string
                solve(s,freq);
                s.pop_back(); //restore the string
                freq[i]++; //restore the curr char freq
                count++; //increment the count
            }
    }
    
    int numTilePossibilities(string tiles) {
        vector<int> freq(26,0); //to store the freq of char in string 'tiles'
        for(int i=0; i<tiles.length(); i++)
            freq[tiles[i]-'A']++;
        string s="";
        solve(s,freq);
        return count;
    }
};