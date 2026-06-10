class Solution {
public:
    int minOperations(string s) {
        int n=s.length();
        string final0 = ""; // alternating string of length n starting with 0
        string final1 = ""; // alternating string of length n starting with 1
        for(int i=0; i<n; i++)
        {
            final0 += to_string(i % 2);
            final1 += to_string((i+1) % 2);
        }

        int flips0 = 0, flips1 = 0;
        for(int i=0; i<n; i++)
        {
            if(s[i] != final0[i])
                flips0++;
            if(s[i] != final1[i])
                flips1++;
        }
        return min(flips0, flips1);
    }
};
/*
# final0 is of the form 010101...
# final1 is of the form 101010...
*/