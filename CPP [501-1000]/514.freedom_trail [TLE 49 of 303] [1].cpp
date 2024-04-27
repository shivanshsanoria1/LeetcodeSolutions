class Solution {
private:
    int solve(string& ring, string& key, int i, int j){
        if(j >= key.length())
            return 0;

        int n=ring.length();
        int minSteps = INT_MAX;

        for(int k=0; k<n; k++)
        {
            if(ring[k] != key[j])
                continue;

            // min distance between indexes k and i 
            // (in both forward and backward direction)
            int minDist = min((k-i+n) % n, (i-k+n) % n);
            
            minSteps = min(minSteps, minDist + solve(ring, key, k, j+1));
        }
        
        // +1 is done since each char requires a button press
        // which is also counted as a step
        return 1 + minSteps;
    }

public:
    int findRotateSteps(string ring, string key) {
        return solve(ring, key, 0, 0);
    }
};