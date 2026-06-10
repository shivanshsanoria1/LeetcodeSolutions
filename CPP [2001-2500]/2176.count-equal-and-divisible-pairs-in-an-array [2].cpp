class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int n=nums.size(), c=0;
        unordered_map<int,vector<int>> mp; //num -> indices of its occurences
        for(int i=0; i<n; i++)
        {
            if(mp.find(nums[i]) != mp.end()) //found in map
                for(auto it: mp[nums[i]])
                    if((i*it)%k==0)
                        c++;
            mp[nums[i]].push_back(i); //push index of nums[i] in map
        }
        return c;
    }
};