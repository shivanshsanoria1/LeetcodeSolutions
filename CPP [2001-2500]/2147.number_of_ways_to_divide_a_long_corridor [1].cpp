class Solution {
private:
    #define MOD int(1e9 + 7)

public:
    int numberOfWays(string corridor) { // T.C.=O(n), S.C.=O(1)
        int count = 0; // counts the num of seats
        for(char ch: corridor)
            if(ch == 'S')
                count++;
        // no way to divide the corridor into sections with 2 seats each, if total seats are 0 or odd
        if(count == 0 || count % 2 == 1)
            return 0;
        // only 1 way to divide the corridor if there are 2 seats in total
        if(count == 2)
            return 1;

        count = 0; // reset the count
        // index of the last odd and even numbered seat respectively (1 based counting)
        int idxO = -1, idxE = -1; 
        long long int ans = 1;
        for(int i=0; i<corridor.length(); i++)
        {
            if(corridor[i] == 'P') // skip the plants
                continue;

            count++;
            if(count % 2 == 1) // odd numbered seat found
                idxO = i;
            else // even numbered seat found
                idxE = i;
                
            // find the distance between 2 sections and multiply it with the ans
            if(idxE != -1 && idxE < idxO)
                ans = (ans * (idxO - idxE)) % MOD;
        }
        return ans;
    }
};