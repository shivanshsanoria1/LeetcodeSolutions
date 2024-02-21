class Solution {
public:
    string longestNiceSubstring(string s) { // T.C.=(26*n^2), S.C.=O(1)
        string ans = "";
        vector<bool> lowerVisited(26, false); // lowercase letters
        vector<bool> upperVisited(26, false); // uppercase letters
        int n = s.length();
        for(int i=0; i<n; i++)
        {
            for(int j=i; j<n; j++)
            {
                if(s[j] >= 'a' && s[j] <= 'z')
                    lowerVisited[s[j] - 'a'] = true;
                else
                    upperVisited[s[j] - 'A'] = true;

                bool isNice = true;
                for(int k=0; k<26; k++)
                    if(!lowerVisited[k] != !upperVisited[k]) // logical XOR- !a != !b
                    {
                        isNice = false;
                        break;
                    }

                if(isNice)
                {
                    string curr = s.substr(i, j-i+1);
                    // skip the curr string if its length <= length of ans
                    if(curr.length() <= ans.length())
                        continue;
                    ans = curr;
                }
            }
            for(int k=0; k<26; k++) // reset the visited vectors
            {
                lowerVisited[k] = false;
                upperVisited[k] = false;
            }
        }
        return ans;
    }
};