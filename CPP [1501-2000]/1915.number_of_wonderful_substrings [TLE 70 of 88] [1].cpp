class Solution {
public:
    // T.C.=O(10*n^2), S.C.=O(10)
    long long wonderfulSubstrings(string word) {
        int n=word.length();
        long long int count = 0;

        for(int i=0; i<n; i++)
        {
            vector<int> freq(10, 0);

            for(int j=i; j<n; j++)
            {
                freq[word[j] - 'a']++;

                int oddFreqCount = 0;

                for(int k=0; k<10; k++)
                    if(freq[k] % 2 == 1)
                        oddFreqCount++;
                
                if(oddFreqCount <= 1)
                    count++;
            }
        }

        return count;
    }
};