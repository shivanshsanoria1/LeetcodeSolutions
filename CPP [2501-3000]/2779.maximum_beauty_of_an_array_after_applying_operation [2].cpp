class Solution {
public:
    // T.C.=O(n*log(n)), S.C.=O(n)
    // Line-sweep algo.
    int maximumBeauty(vector<int>& nums, int k) {
        // point -> num of intervals started(+ive) or ended(-ive)
        map<int, int> mp;
        for(int num: nums)
        {
            mp[num - k]++;
            mp[num + k+1]--;
        }

        int ans = 0;
        int count = 0;
        for(auto it: mp)
        {
            count += it.second;
            ans = max(ans, count);
        }

        return ans;
    }
};

/*
# each num in nums[] can be thought of as an interval [num - k, num + k]
# we need to find the max num of intervals intersecting at some point
# at the point (num - k) the curr interval has started
# at the point (num + k+1) the curr interval has ended
*/