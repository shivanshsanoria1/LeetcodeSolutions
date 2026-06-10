class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.length() != goal.length())
            return false;
        int n=s.length();
        for(int i=0; i<n-1; i++)
            for(int j=i+1; j<n; j++)
            {
                swap(s[i], s[j]);
                if(s == goal)
                    return true;
                swap(s[i], s[j]);
            }
        return false;
    }
};