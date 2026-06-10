class Solution {
public:
    // T.C.=O(n*logn), S.C.=O(n)
    int partitionDisjoint(vector<int>& nums) {
        // num -> freq
        map<int, int> mp;

        for(int num: nums)
            mp[num]++;

        int n=nums.size();
        int maxValLeft = 0;
        
        for(int i=0; i<n-1; i++)
        {
            // max-val in index-range [0, i]
            maxValLeft = max(maxValLeft, nums[i]);

            // decrement the freq of ith element
            mp[nums[i]]--;
            // remove the ith element from map 
            // if its freq reaches 0
            if(mp[nums[i]] == 0)
                mp.erase(nums[i]);
            // smallest element in map
            int minValRight = mp.begin()->first;

            // max-val in index-range [0, i] <=
            // min-val in index-range [i+1, n-1] 
            if(maxValLeft <= minValRight)
                return i+1;
        }

        return -1;
    }
};