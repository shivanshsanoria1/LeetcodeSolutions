class Solution {
public:
    // T.C.=O(n1 + n2), S.C.=O(2*1001)
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) { 
        vector<int> freq1(1001, 0);
        vector<int> freq2(1001, 0);

        for(int num: nums1)
            freq1[num]++;
        for(int num: nums2)
            freq2[num]++;

        vector<int> ans;
        for(int i=0; i<=1000; i++)
            while(freq1[i] > 0 && freq2[i] > 0)
            { 
                ans.push_back(i);
                freq1[i]--;
                freq2[i]--;
            }

        return ans;
    }
};