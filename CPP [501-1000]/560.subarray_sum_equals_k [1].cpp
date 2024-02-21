class Solution {
public:
    int subarraySum(vector<int>& nums, int k) { // T.C.=O(n),  S.C.=O(n)
        int c=0, curr_sum=0;
        unordered_map<int,int> mp; //stores curr_sum -> freq
        for(int i=0; i<nums.size(); i++)
        {
            curr_sum += nums[i];
            if(curr_sum == k)
                c++;
            if(mp.find(curr_sum-k) != mp.end()) //(curr_sum-k) is present in map
                c += mp[curr_sum - k]; //add freq of (curr_sum-k) to count
            mp[curr_sum]++; //add curr_sum in map
        }
        return c;
    }
};