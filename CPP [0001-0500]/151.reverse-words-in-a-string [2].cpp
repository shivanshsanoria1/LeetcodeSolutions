class Solution {
public:
    string reverseWords(string s) {
        string ans;
        for(int i=0;i <s.size(); i++)
        {
            string word;
            if(s[i]==' ') //skip spaces
                continue;
            while(i<s.size() && s[i]!=' ') //find words
            {
                word=word+s[i];
                i++;
            }
            if(ans.empty()) //don't add sapce if the string is empty
                ans=word+ans;
            else
                ans=word+" "+ans;
        }
        return ans;
    }
};