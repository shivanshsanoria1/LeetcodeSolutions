class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) { // T.C.=O(n1 + n2), S.C.=O(2*1001)
        vector<int> freq1(1001, 0), freq2(1001, 0); // vector of size 1001 filled with 0's
        for(int num: nums1)
            freq1[num]++;
        for(int num: nums2)
            freq2[num]++;
        vector<int> ans;
        for(int i=0; i<=1000; i++)
            if(freq1[i] > 0 && freq2[i] > 0)
            {   
                int freq = min(freq1[i], freq2[i]);
                while(freq--)
                    ans.push_back(i);
            }
        return ans;
    }
};