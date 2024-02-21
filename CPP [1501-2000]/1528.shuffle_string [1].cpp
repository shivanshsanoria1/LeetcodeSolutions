class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int n=s.length();
        vector<char> vec(n);
        string ans="";
        for(int i=0; i<n; i++)
            vec[indices[i]]=s[i];
        for(int i=0; i<n; i++)
            ans+=vec[i];
        return ans;
    }
};