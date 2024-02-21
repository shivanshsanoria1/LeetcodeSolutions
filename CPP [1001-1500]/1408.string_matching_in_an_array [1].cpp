class Solution {
public:
    // returns true if s2 is a substring of s1 and false otherwise
    bool isSubstring(string &s1, string &s2) 
    {
        int n1 = s1.length(), n2 = s2.length();
        for(int i=0; i<=n1-n2; i++)
        {
            int j=0;
            for(; j<n2; j++)
                if(s1[i+j] != s2[j])
                    break;
            if(j == n2)
                return true;
        }
        return false;
    }

    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        int n = words.size();
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
            {
                if(i == j)
                    continue;
                // check if words[i] is a substring of words[j]
                if(isSubstring(words[j], words[i]))
                {
                    ans.push_back(words[i]);
                    break;
                }
            }
        return ans;
    }
};