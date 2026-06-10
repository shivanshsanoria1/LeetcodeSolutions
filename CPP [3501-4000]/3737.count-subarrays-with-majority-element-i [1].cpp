class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int count = 0;
        for(int i=0; i<n; i++){
            int targetFreq = 0;
            for(int j=i; j<n; j++){
                if(nums[j] == target)
                    targetFreq++;
                
                if(targetFreq > (j-i+1)/2)
                    count++;
            }
        }

        return count;
    }
};