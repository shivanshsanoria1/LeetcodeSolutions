class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int c=0,min=1000,len,n=strs.size();
        string prefix; // min length string
        for(int i=0; i<n; i++) // finds string of min length
        {
            len=strs[i].length();
            if(len<min)
            {
                min=len;
                prefix=strs[i];
            }
        }
        for(int i=0; i<min; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(strs[j][i] != prefix[i])
                    return prefix.substr(0,c);
            }
            c++;
        }
        return prefix.substr(0,c);
    }
};