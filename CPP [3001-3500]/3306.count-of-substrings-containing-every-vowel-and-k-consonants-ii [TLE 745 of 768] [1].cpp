class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    long long countOfSubstrings(string word, int k) {
        int n=word.length();
        long long int count = 0;
        
        for(int i=0; i <= n-(k+5); i++)
        {
            int consonants = 0;
            string vowelsHash = "00000";

            for(int j=i; j<n && consonants <= k; j++)
            {
                char ch = word[j];

                if(ch == 'a')
                    vowelsHash[0] = '1';
                else if(ch == 'e')
                    vowelsHash[1] = '1';
                else if(ch == 'i')
                    vowelsHash[2] = '1';
                else if(ch == 'o')
                    vowelsHash[3] = '1';
                else if(ch == 'u')
                    vowelsHash[4] = '1';
                else
                    consonants++;

                if(consonants == k && vowelsHash == "11111")
                    count++;
            }
        }

        return count;
    }
};