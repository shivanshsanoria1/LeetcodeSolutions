class Solution {
private:
    // returns true if freq1[] contains freq2[], in other words, 
    // if each element of freq1[] >= the corresponding element of freq2[]
    bool contains(vector<int>& freq1, vector<int>& freq2){
        for(int i=0; i<26; i++)
            if(freq1[i] < freq2[i])
                return false;
        
        return true;
    }

public:
    // T.C.=O(n2 + 26*n1^2), S.C.=O(26)
    long long validSubstringCount(string word1, string word2) {
        vector<int> freq2(26, 0);
        for(char ch: word2)
            freq2[ch - 'a']++;
        
        int n1=word1.length(), n2=word2.length();
        long long int count = 0;
        
        for(int i=0; i <= n1-n2; i++)
        {
            vector<int> freq1(26, 0);

            for(int j=i; j < n1; j++)
            {
                freq1[word1[j] - 'a']++;

                if(contains(freq1, freq2))
                {
                    count += n1 - j;
                    break;
                }
            }
        }

        return count;
    }
};