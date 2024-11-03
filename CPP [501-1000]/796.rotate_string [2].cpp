class Solution {
private:
    // returns true if both the strings s1 and s2 
    // have the exact same freq of chars
    bool sameFreq(string& s1, string& s2){
        vector<int> freq(26, 0);

        for(char ch: s1)
            freq[ch - 'a']++;
        
        for(char ch: s2)
            freq[ch - 'a']--;
        
        for(int i=0; i<26; i++)
            if(freq[i] != 0)
                return false;
        
        return true;
    }

public:
    // T.C.=O(n1 + n2 + n^2), S.C.=O(n1 + 26)
    // n: when 's' and 'goal' both are of equal length
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length())
            return false;
        
        if(!sameFreq(s, goal))
            return false;

        int n = s.length();
        for(int i=0; i<n; i++)
        {
            bool found = true;
            for(int j=0; j<n; j++)
                if(s[(i+j) % n] != goal[j])
                {
                    found = false;
                    break;
                }

            if(found)
                return true;
        }

        return false;
    }
};