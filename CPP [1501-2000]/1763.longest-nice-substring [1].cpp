class Solution {
public:
    string longestNiceSubstring(string s) { // T.C.=(26*n^2), S.C.=O(1)
        string ans = "";
        vector<int> lowerFreq(26, 0); // lowercase letters freq
        vector<int> upperFreq(26, 0); // uppercase letters freq
        int n = s.length();
        for(int i=0; i<n; i++)
        {
            for(int j=i; j<n; j++)
            {
                if(s[j] >= 'a' && s[j] <= 'z')
                    lowerFreq[s[j] - 'a']++;
                else
                    upperFreq[s[j] - 'A']++;

                bool isNice = true;
                for(int k=0; k<26; k++)
                    if((lowerFreq[k] > 0 && upperFreq[k] == 0) || (lowerFreq[k] == 0 && upperFreq[k] > 0))
                    {
                        isNice = false; // curr substring is not nice
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
            for(int k=0; k<26; k++) // reset the frequencies
            {
                lowerFreq[k] = 0;
                upperFreq[k] = 0;
            }
        }
        return ans;
    }
};