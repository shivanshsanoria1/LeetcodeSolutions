class Solution {
private:
    typedef long long int lli;

public:
    // T.C.=O(n*logn), S.C.=O(n)
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        int n=nums.size();
        vector<lli> ans(n, 0);

        // num -> freq
        unordered_map<int, lli> mp;
        // { freq, num }
        set<pair<lli, int>> s;

        for(int i=0; i<n; i++)
        {
            // remove the old freq of nums[i] from set
            s.erase({mp[nums[i]], nums[i]});
            // update the freq of nums[i] in map
            mp[nums[i]] += freq[i];

            // remove nums[i] from map if its new freq reaches 0
            if(mp[nums[i]] == 0)
                mp.erase(nums[i]);
            // add the new freq of nums[i] in set
            else
                s.insert({mp[nums[i]], nums[i]});
            
            // get the highest freq from set
            if(!s.empty())
                ans[i] = s.rbegin()->first;
        }
        
        return ans;
    }
};