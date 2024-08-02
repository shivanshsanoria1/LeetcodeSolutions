class Solution {
private:
    bool matchFreq(string& s1, string& s2, char mode){
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        for(int i = mode == 'e' ? 0 : 1; i<s1.length(); i += 2)
        {
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }

        for(int i=0; i<26; i++)
            if(freq1[i] != freq2[i])
                return false;

        return true;
    }

public:
    // T.C.=O(n + 26), S.C.=O(2*26)
    bool checkStrings(string s1, string s2) {
        return matchFreq(s1, s2, 'e') && matchFreq(s1, s2, 'o');
    }
};
/*
# mode = 'e' or 'o' representing even and odd mode respectively
# for even mode: index i is even, i = 0,2,4,6,...
# for odd mode: index i is odd, i = 1,3,5,7,...
*/