class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) { // T.C.=O(n) , S.C.=O(n)
        vector<int> ans(2);
        unordered_map<int,int> mp; //num -> index
        for(int i=0; i<nums.size(); i++)
        {
            if(mp.find(target-nums[i]) != mp.end()) //(target-curr element) present in map
            {
                ans[0]=mp[target-nums[i]]; //add the index of (target-curr element) in ans
                ans[1]=i; //add the index of curr element in ans
                break;
            }
            else //(target-curr element) not present in map
                mp[nums[i]]=i; //add curr element and its index in map
        }
        return ans;
    }
};