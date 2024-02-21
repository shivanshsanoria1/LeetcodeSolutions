class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        vector<int> ans;
        unordered_set<int> s1(nums1.begin(),nums1.end()); //add nums1 array into set s1 to eliminate duplicates
        unordered_set<int> s2(nums2.begin(),nums2.end()); //add nums2 array into set s2 to eliminate duplicates
        unordered_set<int> s3(nums3.begin(),nums3.end()); //add nums3 array into set s3 to eliminate duplicates
        unordered_map<int,int> mp;
        for(auto it: s1)
            mp[it]++;
        for(auto it: s2)
            mp[it]++;
        for(auto it: s3)
            mp[it]++;
        for(auto it: mp)
            if(it.second >= 2) //num appears in 2 or more sets
                ans.push_back(it.first);
        return ans;
    }
};