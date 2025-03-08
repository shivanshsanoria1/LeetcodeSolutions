class Solution {
public:
    // T.C.=O(n + 10), S.C.=O(10)
    string findValidPair(string s) {
        vector<int> freq(10, 0);
        for(char dig: s)
            freq[dig - '0']++;
        
        for(int i=0; i<s.length()-1; i++)
        {
            int dig1 = s[i] - '0';
            int dig2 = s[i+1] - '0';

            if(dig1 != dig2 && freq[dig1] == dig1 && freq[dig2] == dig2)
                return s.substr(i, 2);
        }

        return "";
    }
};