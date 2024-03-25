class Solution {
private:
    // returns the length of suffix common in both s1 and s2
    int commonSuffixLength(string& s1, string& s2) {
        int n1=s1.length(), n2=s2.length();
        int suffixLen = 0;
        
        for(int i=n1-1, j=n2-1; i>=0 && j>=0; i--, j--)
        {
            if(s1[i] != s2[j])
                return suffixLen;
            suffixLen++;
        }

        return suffixLen;
    }

public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        // find the index of min-length string in 'wordsContainer'
        // if multiple min-length string are found, choose the one with smaller index
        int minLenIdx = 0;
        for(int i=0; i<wordsContainer.size(); i++)
            if(wordsContainer[i].length() < wordsContainer[minLenIdx].length())
                minLenIdx = i;

        vector<int> ans;

        for(string& query: wordsQuery)
        {
            int idx = -1;
            int maxSuffixLen = 0;

            for(int i=0; i<wordsContainer.size(); i++)
            {
                int suffixLen = commonSuffixLength(wordsContainer[i], query);

                if(suffixLen == 0)
                    continue;

                if(suffixLen > maxSuffixLen)
                {
                    maxSuffixLen = suffixLen;
                    idx = i;
                }
                else if(suffixLen == maxSuffixLen && wordsContainer[i].length() < wordsContainer[idx].length())
                    idx = i;
            }

            ans.push_back(idx == -1 ? minLenIdx : idx);
        }
        
        return ans;
    }
};