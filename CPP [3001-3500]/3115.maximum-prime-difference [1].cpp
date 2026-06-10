class Solution {
private:
    bool isPrime(int n){
        if(n <= 1)
            return false;
        if(n == 2)
            return true;
        if(n % 2 == 0)
            return false;

        for(int i=3; i*i<=n; i+=2)
            if(n % i == 0)
                return false;

        return true;
    }

public:
    // T.C.=O(n*sqrt(x)), S.C.=O(1)
    // x: max number in nums[]
    int maximumPrimeDifference(vector<int>& nums) {
        int n=nums.size();

        // find the 1st prime from left and right side
        int left = 0, right = n-1;

        while(left < n && !isPrime(nums[left]))
            left++;
        while(right >= 0 && !isPrime(nums[right]))
            right--;
            
        return right - left;
    }
};