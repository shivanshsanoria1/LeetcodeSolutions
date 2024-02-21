class Solution {
public:
    bool isPrime(int num){
        if(num < 2)
            return false;
        if(num == 2)
            return true;
        if(num % 2 == 0)
            return false;
        for(int i=3; i*i <= num; i += 2)
            if(num % i == 0)
                return false;
        return true;
    }

    int diagonalPrime(vector<vector<int>>& nums) { // T.C.=O(n*sqrt(n)), S.C.=O(1)
        int n=nums.size();
        int maxPrime = 0;
        for(int i=0; i<n; i++)
        {
            if(isPrime(nums[i][i])) // left-diagonal
                maxPrime = max(maxPrime, nums[i][i]);
            if(isPrime(nums[i][n-i-1])) // right-diagonal
                maxPrime = max(maxPrime, nums[i][n-i-1]);
        }
        return maxPrime;
    }
};