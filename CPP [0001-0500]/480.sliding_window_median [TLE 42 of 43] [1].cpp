class Solution {
public:
    // T.C.=O((n-k)*k*log(k)), S.C.=O(k)
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<double> medians;
        for(int i=0; i<=n-k; i++)
        {
            // fill with elements in index range [i, i+k-1]
            vector<int> temp(nums.begin() + i, nums.begin() + i+k);
            sort(temp.begin(), temp.end());

            double median = k % 2 == 0 ? ((double)temp[k/2 - 1] + temp[k/2])/2 : temp[k/2];
            medians.push_back(median);
        }

        return medians;
    }
};