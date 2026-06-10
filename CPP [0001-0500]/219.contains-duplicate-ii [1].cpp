class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) { //T.C.=O(n) , S.C.=O(n)
        unordered_map<int,int> mp; //num -> index
        for(int i=0; i<nums.size(); i++)
        {
            if(mp.find(nums[i]) != mp.end()) //nums[i] present in map
                if(i-mp[nums[i]] <= k) //diff between curr index and index of prev occurence of nums[i] must be <= k
                    return true;
            mp[nums[i]]=i; //add nums[i] and i to map
        }
        return false;
    }
};