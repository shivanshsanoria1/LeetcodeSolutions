class Solution {
public:
    string s1="qwertyuiop"; //row 1 (lowercase)
    string S1="QWERTYUIOP"; //row 1 (uppercase)
    string s2="asdfghjkl"; //row 2 (lowercase)
    string S2="ASDFGHJKL"; //row 2 (uppercase)
    string s3="zxcvbnm"; //row 3 (lowercase)
    string S3="ZXCVBNM"; //row 3 (uppercase)
    
    bool inRow(string s) //returns true if string s lies in a single row
    {
        int c1=0, c2=0, c3=0;
        for(int i=0; i<s.length(); i++)
        {
            for(int j=0; j<s1.length(); j++) //check if s[i] lies in row 1
                if(s[i]==s1[j] || s[i]==S1[j])
                {
                    c1=1;
                    break;
                }
            for(int j=0; j<s2.length(); j++) //check if s[i] lies in row 2
                if(s[i]==s2[j] || s[i]==S2[j])
                {
                    c2=1;
                    break;
                }
            for(int j=0; j<s3.length(); j++) //check if s[i] lies in row 3
                if(s[i]==s3[j] || s[i]==S3[j])
                {
                    c3=1;
                    break;
                }
            if(c1+c2+c3 > 1) //string s lies in more than 2 rows
                return false;
        }
        return true;
    }
    
    vector<string> findWords(vector<string>& words) {
        vector<string> ans;
        for(int i=0; i<words.size(); i++)
            if(inRow(words[i])==true)
                ans.push_back(words[i]);
        return ans;
    }
};