class Solution {
private:
    bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

public:
    // T.C.=O(n^2), S.C.=O(1)
    long long countVowels(string word) {
        long long int ans = 0;
        int n=word.length();
        for(int i=0; i<n; i++)
        {
            int count = 0;
            for(int j=i; j<n; j++)
            {
                if(isVowel(word[j]))
                    count++;
                ans += count;
            }
        }
        return ans;
    }
};