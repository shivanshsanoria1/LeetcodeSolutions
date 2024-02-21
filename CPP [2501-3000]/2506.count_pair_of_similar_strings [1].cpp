class Solution {
public:
    int similarPairs(vector<string>& words) { // T.C.=O(26*n^2), S.C.=O(26*n)
        int n=words.size();
        int count = 0;
        for(int i=0; i<n-1; i++)
        {
            vector<bool> vec1(26, false);
            for(char ch: words[i])
                vec1[ch - 'a'] = true;
            for(int j=i+1; j<n; j++)
            {
                vector<bool> vec2(26, false);
                for(char ch: words[j])
                    vec2[ch - 'a'] = true;
                bool match = true;
                for(int k=0; k<26; k++)
                    if(!vec1[k] != !vec2[k]) // logical XOR
                    {
                        match = false;
                        break;
                    }
                if(match)
                    count++;
            }
        }
        return count;
    }
};