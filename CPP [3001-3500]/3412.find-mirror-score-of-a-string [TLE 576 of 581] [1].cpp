class Solution {
public:
    // T.C.=O(n^2), S.C.=O(n)
    long long calculateScore(string s) {
        int n = s.length();
        vector<bool> marked(n, false);
        long long int score = 0;

        for(int i=0; i<n; i++)
        {
            char mirror = 'a' + (25 - (s[i] - 'a'));

            for(int j=i-1; j>=0; j--)
            {
                if(s[j] != mirror || marked[j])
                    continue;
                
                marked[i] = true;
                marked[j] = true;
                score += i-j;
                break;
            }
        }

        return score;
    }
};