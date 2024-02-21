class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans(2);
        unordered_set<int> s1(nums1.begin(),nums1.end()); //add nums1 elements into set1
        unordered_set<int> s2(nums2.begin(),nums2.end()); //add nums2 elements into set2
        for(auto it: s1) //iterate set1
            if(s2.count(it)==0) //not found in set2
                ans[0].push_back(it);
        for(auto it: s2) //iterate set2
            if(s1.count(it)==0) //not found in set2
                ans[1].push_back(it);
        return ans;
    }
};