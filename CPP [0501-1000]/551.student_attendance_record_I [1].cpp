class Solution {
public:
    bool checkRecord(string s) {
        int n=s.length(), a=0, l=0;
        if(s[0]=='A') //check for 0th day
            a++;
        if(1<n && s[1]=='A') //check for 1st day
            a++;
        if(a>1) //absent for more than 1 day
            return false;
        for(int i=2; i<n; i++)
        {
            if(s[i]=='A')
                a++;
            if(a>1) //absent for more than 1 day
                return false;
            if(s[i]=='L' && s[i-1]=='L' && s[i-2]=='L') //late for 3 consecutive days
                return false;
        }
        return true;
    }
};