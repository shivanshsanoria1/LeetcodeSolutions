class Solution {
public:
    bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    int countVowelSubstrings(string word) { // T.C.=O(n^2)
        int n=word.length();
        int count = 0;
        for(int i=0; i<n-4; i++)
        {
            unordered_set<char> s;
            for(int j=i; j<n; j++)
            {
                if(isVowel(word[j]))
                    s.insert(word[j]);
                else
                    break;
                if(s.size() == 5)
                    count++;
            }
        }
        return count;
    }
};