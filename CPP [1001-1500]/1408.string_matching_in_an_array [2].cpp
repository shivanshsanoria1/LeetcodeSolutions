class Solution {
public:
    // T.C.=O(n^2 * m), S.C.=O(1)
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
                if(words[j].find(words[i]) != string::npos)
                {
                    ans.push_back(words[i]);
                    break;
                }
            }

        return ans;
    }
};