class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) { 
        vector<bool> visited1(1001, false), visited2(1001, false); // vector of size 1001 filled with false's
        for(int num: nums1)
            visited1[num] = true;
        for(int num: nums2)
            visited2[num] = true;
        vector<int> ans;
        for(int i=0; i<=1000; i++)
            if(visited1[i] && visited2[i])
                ans.push_back(i);
        return ans;
    }
};
// T.C.=O(n1 + n2), S.C.=O(2 * 1001)