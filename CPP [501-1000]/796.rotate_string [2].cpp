class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) // both strings must be of same length
            return false;
        if(s == goal)
            return true;
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