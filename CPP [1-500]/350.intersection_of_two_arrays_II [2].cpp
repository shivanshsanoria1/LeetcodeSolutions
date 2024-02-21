class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) { // T.C.=O(n1 + n2), S.C.=O(1001)
        vector<int> freq(1001, 0); // vector of size 1001 filled with 0's
        for(int num: nums1)
            freq[num]++;
        vector<int> ans;
        for(int num: nums2)
            if(freq[num] > 0)
            {
                ans.push_back(num);
                freq[num]--;
            }
        return ans;
    }
};