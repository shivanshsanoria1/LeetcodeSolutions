class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    int getLargestOutlier(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        int maxOutlier = -1001;
        unordered_set<int> s;

        for(int num: nums)
        {
            // num: special sum, (totalSum - 2*num): outlier
            if(s.find(totalSum - 2*num) != s.end())
                maxOutlier = max(maxOutlier, totalSum - 2*num);
            // num: outlier, (totalSum - num)/2: special sum
            if((totalSum - num) % 2 == 0 && s.find((totalSum - num)/2) != s.end())
                maxOutlier = max(maxOutlier, num);

            s.insert(num);
        }
        
        return maxOutlier;
    }
};

/*
# totalSum - specialSum - outlier == specialSum
# totalSum - 2*specialSum == outlier
# totalSum - outlier == 2*specialSum
*/