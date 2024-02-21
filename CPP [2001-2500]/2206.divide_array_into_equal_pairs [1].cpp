class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int> mp; //num->freq
        for(int i=0; i<nums.size(); i++)
            mp[nums[i]]++;
        for(auto it:mp)
            if(it.second%2 != 0) //odd freq
                return false;
        return true;
    }
};