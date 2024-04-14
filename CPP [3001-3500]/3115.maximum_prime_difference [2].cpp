class Solution {
private:
    void sieveOfEratosthenes(vector<bool>& primes){
        // last number is 'm'
        int m = primes.size()-1;

        primes[0] = false;
        primes[1] = false;

        for(int p=2; p*p <= m; p++)
        {
            if(!primes[p])
                continue;
            for(int i = p*p; i <= m; i += p)
                primes[i] = false;
        }
    }

public:
    // T.C.=O(m*log(logm) + n), S.C.=O(m)
    // m: max number in nums[]
    int maximumPrimeDifference(vector<int>& nums) {
        int maxNum = *max_element(nums.begin(), nums.end());

        // find the primes in range [1, maxNum]
        vector<bool> primes(maxNum + 1, true);
        sieveOfEratosthenes(primes);

        int n=nums.size();

        // find the 1st prime from left and right side
        int left = 0, right = n-1;

        while(left < n && !primes[nums[left]])
            left++;
        while(right >= 0 && !primes[nums[right]])
            right--;
            
        return right - left;
    }
};
// It is guranteed that nums[] has atleast 1 prime