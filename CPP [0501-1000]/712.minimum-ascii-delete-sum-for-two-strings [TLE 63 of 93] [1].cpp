class Solution {
private:
    int solve(string& s1, string& s2, int i, int j){
        int n1=s1.length(), n2=s2.length();

        // both s1 and s2 are exhausted, so 
        // no more operations are needed
        if(i == n1 && j == n2)
            return 0;
        
        // s1 is exhausted; delete the
        // remaining (n2 - j) chars from s2
        if(i == n1)
        {
            int sum = 0;
            for(int k=j; k<n2; k++)
                sum += int(s2[k]);

            return sum;
        }
        
        // s2 is exhausted; delete the
        // remaining (n1 - i) chars from s1
        if(j == n2)
        {
            int sum = 0;
            for(int k=i; k<n1; k++)
                sum += int(s1[k]);
                
            return sum;
        }

        if(s1[i] == s2[j])
            return solve(s1, s2, i+1, j+1);
        
        int deleteFromS1 = int(s1[i]) + solve(s1, s2, i+1, j);
        int deleteFromS2 = int(s2[j]) + solve(s1, s2, i, j+1);

        return min(deleteFromS1, deleteFromS2);
    }

public:
    // Recursion
    int minimumDeleteSum(string s1, string s2) {
        return solve(s1, s2, 0, 0);
    }
};

// similar: [72. edit-distance]