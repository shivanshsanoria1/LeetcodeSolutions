class Solution {
private:
    // returns the Smallest-Prime-Factor of a num
    int findSPF(int num){
        if(num % 2 == 0)
            return 2;

        for(int i=3; i*i <= num; i += 2)
            if(num % i == 0)
                return i;
        
        // num is either 1 or a odd-prime
        return num;
    }

public:
    // T.C.=O(n*sqrt(m)), S.C.=O(1)
    // m: max-val in nums[]
    int minOperations(vector<int>& nums) {
        int ops = 0; // operations
        // curr basically acts as nums[i]
        int curr = nums.back();

        for(int i=nums.size()-1; i>0; i--)
        {
            // no operation needed
            if(nums[i-1] <= curr)
            {
                // don't forget to update curr
                // for the next iteration
                curr = nums[i-1];
                continue;
            }
                
            int spf = findSPF(nums[i-1]);

            // even after reducing the prev num, it is still > curr
            if(spf > curr)
                return -1;
            
            // reduce the prev num and make it the new curr,
            // thereby taking 1 operation
            curr = spf;
            ops++;
        }

        return ops;
    }
};

/*
# GPD (Greatest-Proper-Divisor) of a num is the greatest divisor
  of a num which is not equal to that num 
# dividing a num by its GPD is equivalent to 
  finding that num's Smallest-Prime-Factor (SPF)
# (num / gpd) = spf
*/