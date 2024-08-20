class Solution {
private:
    int solve(vector<int>& nums, bool player, int i){
        int n=nums.size();
        if(i >= n)
            return 0;

        int res = player ? INT_MIN : INT_MAX;
        int sum = 0;

        for(int j=0; j<3 && i+j < n; j++)
        {
            sum += nums[i+j];

            // Alice is trying to maximize her score
            if(player)
                res = max(res, sum + solve(nums, !player, i+j+1));
            // Bob is trying to minimize Alice's score
            else
                res = min(res, solve(nums, !player, i+j+1));
        }

        return res;
    }

public:
    // T.C.=O(3^n), S.C.=O(n)
    // Recursion
    string stoneGameIII(vector<int>& stoneValue) {
        int totalSum = accumulate(stoneValue.begin(), stoneValue.end(), 0);
        int scoreA = solve(stoneValue, true, 0);
        int scoreB = totalSum - scoreA;

        if(scoreA == scoreB)
            return "Tie";
        
        return scoreA > scoreB ? "Alice" : "Bob";
    }
};