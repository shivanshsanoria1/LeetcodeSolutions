class Solution {
public:
    // T.C.=O(m + n), S.C.=O(1)
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m=rolls.size();
        int Sm = accumulate(rolls.begin(), rolls.end(), 0);
        int Sn = mean*(m+n) - Sm;

        if(Sn < n || Sn > 6*n)
            return {};
        
        vector<int> missingRolls(n, Sn / n);
        for(int i=0, rem = Sn % n; rem > 0; i++, rem--)
            missingRolls[i]++;

        return missingRolls;
    }
};

/*
# Sm, Sn: sum of m, n observations respectively
# mean = (Sm + Sn) / (m + n)
  Sn = mean*(m + n) - Sm
# min val of Sn = 1*n (when all observations are 1)
  max val of Sn = 6*n (when all observations are 6)
  therefore, Sn must be in range [1*n, 6*n]
# calculate (Sn / n) and (Sn % n), 
# fill an array of size n with (Sn / n)
# increment (Sn % n) observations by 1
*/