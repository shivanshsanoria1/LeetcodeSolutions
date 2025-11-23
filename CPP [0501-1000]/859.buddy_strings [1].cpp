class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.length() != goal.length())
            return false;

        if(s == goal)
        {
            vector<int> freq(26, 0);
            for(char ch: s)
            {
                freq[ch - 'a']++;
                if(freq[ch - 'a'] > 1) // repeated char found
                    return true;
            }
            return false; // no repeated char found
        }

        int n=s.length();
        int idx1 = -1, idx2 = -1;
        for(int i=0; i<n; i++)
        {
            if(s[i] == goal[i])
                continue;
            if(idx1 == -1)
                idx1 = i;
            else if(idx2 == -1)
                idx2 = i;
            else // non-matching chars at more than 2 indexes
                return false;
        }
        // at this point, idx1 != -1 as s != goal
        if(idx2 == -1)
            return false;
        // swapping the chars at idx1 and idx2 in 's' will make it the same as 'goal'
        return s[idx1] == goal[idx2] && s[idx2] == goal[idx1];
    }
};