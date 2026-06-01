class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    int minAbsoluteDifference(vector<int>& nums) {
        const int n = nums.size();
        int minDiff = n;
        for(int i=0; i<n; i++){
            if(nums[i] != 1)
                continue;

            for(int j=i+1; j<n; j++)
                if(nums[j] == 2){
                    minDiff = min(minDiff, abs(i-j));
                    break;
                }
                
            for(int j=i-1; j>=0; j--)
                if(nums[j] == 2){
                    minDiff = min(minDiff, abs(i-j));
                    break;
                }
        }

        return minDiff == n ? -1 : minDiff;
    }
};