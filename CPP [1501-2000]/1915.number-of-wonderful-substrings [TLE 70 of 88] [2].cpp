class Solution {
public:
    // T.C.=O(n^2), S.C.=O(10)
    long long wonderfulSubstrings(string word) {
        int n=word.length();
        long long int count = 0;

        for(int i=0; i<n; i++)
        {
            vector<int> freq(10, 0);
            int oddFreqCount = 0;

            for(int j=i; j<n; j++)
            {
                // freq change from odd to even
                if(freq[word[j] - 'a'] % 2 == 1)
                    oddFreqCount--;
                // freq change from even to odd
                else
                    oddFreqCount++;

                freq[word[j] - 'a']++;
                
                if(oddFreqCount <= 1)
                    count++;
            }
        }

        return count;
    }
};