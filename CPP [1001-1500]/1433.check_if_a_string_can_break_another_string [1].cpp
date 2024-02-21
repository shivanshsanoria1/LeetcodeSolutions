class Solution {
private:
    // returns true if for some permutation of s1 
    // every char of s1 >= every char of s2, and false otherwise
    bool canBreak(string& s1, string& s2){
        vector<int> freq1(26, 0);
        for(char ch: s1)
            freq1[ch - 'a']++;

        for(char ch: s2)
        {
            bool matched = false;

            for(int i=ch-'a'; i<26; i++)
                if(freq1[i] > 0)
                {
                    freq1[i]--;
                    matched = true;
                    break;
                }

            if(!matched)
                return false;
        }
        return true;
    }

public:
    bool checkIfCanBreak(string s1, string s2) {
        return canBreak(s1, s2) || canBreak(s2, s1);
    }
};