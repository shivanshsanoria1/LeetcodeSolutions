class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans;
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        for(int i=0; i<nums1.size(); i++)
            mp1[nums1[i]]++;
        for(int i=0; i<nums2.size(); i++)
            mp2[nums2[i]]++;
        vector<int> vec1;
        vector<int> vec2;
        for(auto it: mp1) //iterate map1
            if(mp2.find(it.first) == mp2.end()) //not found in map2
                vec1.push_back(it.first);
        for(auto it: mp2) //iterate map2
            if(mp1.find(it.first) == mp1.end()) //not found in map1
                vec2.push_back(it.first);
        ans.push_back(vec1);
        ans.push_back(vec2);
        return ans;
    }
};