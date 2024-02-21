class Solution {
public:
    bool isVowelString(string& s, int start, int end){
        bool a=false, e=false, i= false, o=false, u=false;
        for(int idx = start; idx <= end; idx++)
        {
            if(s[idx] == 'a')
                a = true;
            else if(s[idx] == 'e')
                e = true;
            else if(s[idx] == 'i')
                i = true;
            else if(s[idx] == 'o')
                o = true;
            else if(s[idx] == 'u')
                u = true;
            else // non-vowel found
                return false;
        }
        return a && e && i && o && u;
    }

    int countVowelSubstrings(string word) { // T.C.=O(n^3)
        int n=word.length();
        int count = 0;
        for(int i=0; i<n-4; i++)
            for(int j=i+4; j<n; j++)
                if(isVowelString(word, i, j))
                    count++;
        return count;
    }
};