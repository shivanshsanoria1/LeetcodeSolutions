class Solution {
private:
    // returns true if its possible to split every num in nums[] into 
    // segments of max size 'limit' using a max of 'maxOps' operations
    bool isPossible(vector<int>& nums, int maxOps, int limit){
        int ops = 0;
        for(int num: nums)
        {
            // ceil division - 1
            ops += num % limit == 0 ? num/limit - 1 : num/limit;
            if(ops > maxOps)
                return false;
        }

        return true;
    }

public:
    // T.C.=O(n*m), S.C.=O(1)
    // m: max element in nums[]
    int minimumSize(vector<int>& nums, int maxOperations) {
        // range of values which each num in nums[] 
        // can take after splitting is [1, maxVal]
        int maxVal = *max_element(nums.begin(), nums.end());

        for(int limit = 1; limit <= maxVal; limit++)
            if(isPossible(nums, maxOperations, limit))
                return limit;

        return -1;
    }
};

// prerequisite: [1283. find-the-smallest-divisor-given-a-threshold]
// similar: [2064. minimized-maximum-of-products-distributed-to-any-store]