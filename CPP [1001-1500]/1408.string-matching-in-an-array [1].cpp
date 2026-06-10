class Solution {
private:
    // returns true if s2 is a substring of s1 and false otherwise
    bool isSubstring(string& s1, string& s2){
        int n1 = s1.length(), n2 = s2.length();
        if(n1 < n2)
            return false;

        for(int i=0; i<=n1-n2; i++)
        {
            int j = 0;
            while(j < n2 && s1[i+j] == s2[j])
                j++;
            if(j == n2)
                return true;
        }

        return false;
    }

public:
    // T.C.=O(n^2 * m^2), S.C.=O(1)
    // n: size of words[], m: max-length of word in words[]
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        vector<string> ans;
        
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