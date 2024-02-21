class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp; //(curr_sum%k)->(curr_sum index)
        mp[0]=-1; //add {0,-1} in map (to avoid adding valid subarrays of length 1)
        int curr_sum=0;
        for(int i=0; i<nums.size(); i++)
        {
            curr_sum+=nums[i];
            int rem=curr_sum%k;
            if(mp.find(rem) != mp.end()) //rem present in map
            {
                if(i-mp.find(rem)->second >1) //valid subarray length must be >1
                    return true;
            }
            else
                mp[rem]=i; //add rem and its index in map
        }
        return false;
    }
};