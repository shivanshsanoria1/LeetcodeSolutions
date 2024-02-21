class Solution {
public:
    int totalFruit(vector<int>& fruits) { // sliding-window, T.C.=O(n), S.C.=O(1)
        int n=fruits.size();
        int left = 0, right = 0;
        int ans = 0;
        unordered_map<int, int> mp; // num -> freq
        while(right < n)
        {
            mp[fruits[right]]++;
            if(mp.size() == 3) // 3rd distinct num found in window
            {
                // reduce the size of window by moving left forward
                // until window has 2 distinct nums
                while(mp.size() != 2)
                {
                    mp[fruits[left]]--;
                    if(mp[fruits[left]] == 0) // freq reaches 0
                        mp.erase(fruits[left]); // remove that num from map
                    left++;
                }
            }
            // curr window size is (right - left + 1)
            ans = max(ans, right - left + 1);
            right++;
        }
        return ans;
    }
};
/*
# just find the longest subarray with atmost 2 distinct numbers
# at any time, the num of distinct nums in window must be atmost 2
# if it reaches 3, reduce the size of window until the num of distinct nums become 2
*/