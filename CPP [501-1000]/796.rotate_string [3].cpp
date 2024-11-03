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
    // T.C.=O(n1 + n2), S.C.=O(n1 + 26)
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length())
            return false;

        if(s == goal)
            return true;
        
        if(!sameFreq(s, goal))
            return false;

        // append string 's' to itself
        s += s;
        // check if 'goal' is a subtring if modified 's'
        return s.find(goal) != string::npos;
    }
};