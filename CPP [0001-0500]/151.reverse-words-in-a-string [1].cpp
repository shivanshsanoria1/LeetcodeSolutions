class Solution {
public:
    string removeExtraSpaces(string s)
    {
        string str;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]!=' ')
            {
                str=str+s[i];
                if(i+1<s.size() && s[i+1]==' ')
                    str=str+' ';
            }
        }
        if(str[str.size()-1]==' ') //remove the extra space at end (if present)
            str.erase(str.size()-1,1);
        return str;
    }
    
    string reverseWords(string s) {
        string ans;
        s=removeExtraSpaces(s);
        int right=s.size()-1;
        int left=right;
        while(left>=0)
        {
            string word;
            while(s[left]!=' ' && left>0)
                left--;
            for(int i=(left==0?left:left+1); i<=right; i++)
                word=word+s[i];
            ans=ans+word;
            if(s[left]==' ')
                ans=ans+' ';
            right=left-1;
            left=right;
        }
        return ans;
    }
};