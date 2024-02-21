class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) // both strings must be of same length
            return false;
        if(s == goal)
            return true;
        int n = s.length();
        int end = 0;
        for(int i=1; i<n; i++)
        {
            string curr = "";
            for(int j=i; curr.length() != n; j=(j+1) % n)
                curr += s[j];
            if(curr == goal)
                return true;
            end++;
        }
        return false;
    }
};