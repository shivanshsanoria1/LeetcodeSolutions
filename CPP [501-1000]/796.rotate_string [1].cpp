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

        // generate all possible rotations of 's'
        // and check if any of them matches with 'goal'
        for(int i=0; i<s.length(); i++)
            if(s.substr(i) + s.substr(0, i) == goal)
                return true;

        return false;
    }
};