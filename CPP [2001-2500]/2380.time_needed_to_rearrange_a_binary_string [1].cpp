class Solution {
public:
    // T.C.=O(??), S.C.=O(n)
    int secondsToRemoveOccurrences(string s) {
        int n=s.length();

        int ones = count(s.begin(), s.end(), '1');
        int zeros = n - ones;

        string finalStr = string(ones, '1');
        string zeroStr = string(zeros, '0');
        finalStr += zeroStr;

        int steps = 0;
        while(s != finalStr)
        {
            for(int i=0; i<n-1; i++)
                if(s[i] == '0' && s[i+1] == '1')
                {
                    swap(s[i], s[i+1]);
                    i++;
                }
            
            steps++;
        }

        return steps;
    }
};