class Solution {
public:
    // T.C.=O(n + m), S.C.=O(n + m)
    // m: max abs diff between a num in nums1[] and a num in nums2[]
    // using Counting-sort
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<int> diffs(n, 0);
        for(int i=0; i<n; i++)
            diffs[i] = abs(nums1[i] - nums2[i]);
        
        int maxDiff = *max_element(diffs.begin(), diffs.end());
        vector<int> freq(maxDiff + 1, 0);
        for(int diff: diffs)
            freq[diff]++;
        
        int k = k1 + k2;
        for(int i=freq.size()-1; i>=1 && k>0; i--)
        {
            if(freq[i] == 0)
                continue;
            
            int reduce = min(freq[i], k);
            freq[i] -= reduce;
            freq[i-1] += reduce;
            k -= reduce;
        }

        long long int sum = 0;
        for(int i=1; i<freq.size(); i++)
            sum += (long long int)freq[i] * i * i;

        return sum;
    }
};