class Solution {
public:
    // T.C.=O(n^2), S.C.=O(26)
    int numberOfSubstrings(string s, int k) {
        int n = s.length();
        int count = 0;

        for(int i=0; i<n; i++)
        {
            vector<int> freq(26, 0);
            
            for(int j=i; j<n; j++)
                if(++freq[s[j] - 'a'] == k)
                {
                    // all the substrings in index-range 
                    // [right, n-1] are valid
                    count += n-j;
                    break;
                }
        }

        return count;
    }
};