class Solution {
public:
    bool vaildSubstring(string str, vector<int> count_lower, vector<int> count_upper)
    {
        for(int i=0; i<str.length(); i++)
        {
            if(str[i]>='a' && str[i]<='z')
                count_lower[str[i]-'a']--;
            else
                count_upper[str[i]-'A']--;
        }
        for(int i=0; i<26; i++)
            if(count_lower[i]>0 || count_upper[i]>0)
                return false;
        return true;
    }
    
    string minWindow(string s, string t) {
        int n1=s.length(), n2=t.length();
        int min_len=n1;
        string ans;
        if(n1<n2)
            return ans;
        if(s==t) //both strings are same
            return s;
        vector<int> count_lower(26,0), count_upper(26,0);
        for(int i=0; i<n2; i++)
        {
            if(t[i]>='a' && t[i]<='z')
                count_lower[t[i]-'a']++;
            else
                count_upper[t[i]-'A']++;
        }
        for(int i=0; i<n1; i++)
        {
            string temp;
            for(int j=i; j<n1; j++)
            {
                temp=temp+s[j];
                if(temp.length()>=n2 && vaildSubstring(temp,count_lower,count_upper)==true)
                {
                    if(temp.length()<=min_len)
                    {
                        min_len=temp.length();
                        ans=temp;
                    }
                }
            }
        }
        return ans;
    }
};