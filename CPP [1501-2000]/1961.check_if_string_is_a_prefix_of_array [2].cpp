class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        int l=s.length(), index=0, i=0,j=0;
        while(index < l && i < words.size())
        {
            if(s[index] != words[i][j])
                return false;
            else
            {
                index++;
                j++;
            }
            if(j == words[i].length()) //move to next word
            {
                i++; //increment i
                j=0; //reset j
            }
        }
        if(index==l && j==0) //string s is finished and j is reset
            return true;
        return false;
    }
};