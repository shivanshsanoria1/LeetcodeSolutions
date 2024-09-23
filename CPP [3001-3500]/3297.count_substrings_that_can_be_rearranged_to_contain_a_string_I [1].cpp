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
    // T.C.=O(n2 + 26*n1), S.C.=O(26)
    // Sliding-Window
    long long validSubstringCount(string word1, string word2) {
        vector<int> freq2(26, 0);
        for(char ch: word2)
            freq2[ch - 'a']++;
        
        int n1=word1.length();
        int left = 0, right = 0;
        vector<int> freq1(26, 0);
        long long int count = 0;

        while(right < n1)
        {
            freq1[word1[right] - 'a']++;

            while(contains(freq1, freq2))
            {
                // substring in index range [right, n1-1] is valid
                count += n1 - right;

                freq1[word1[left] - 'a']--;
                left++;
            }

            right++;
        }

        return count;
    }
};