class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {  // T.C.O(n^2), S.C.=O(1)
        int n=words.size();
        int count = 0;
        for(int i=0; i<n-1; i++)
            for(int j=i+1; j<n; j++)
            {
                string word2 = words[j];
                reverse(word2.begin(), word2.end());
                if(words[i] == word2)
                    count++;
            }
        return count;
    }
};