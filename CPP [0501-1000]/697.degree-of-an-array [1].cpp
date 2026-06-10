class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> mp; // num -> freq
        unordered_set<int> s; // to store nums with max freq
        int degree = 0; // max freq
        for(int num: nums)
        {
            mp[num]++;
            if(mp[num] > degree) // new max freq found
            {
                degree = mp[num];
                s.clear();
                s.insert(num);
            }
            else if(mp[num] == degree) // another max freq found
                s.insert(num);
        }
        
        int n=nums.size();
        int ans = n;
        for(int num: s)
        {
            int startIdx = -1, endIdx = -1;
            for(int i=0; i<n; i++)
                if(nums[i] == num)
                {
                    startIdx = i;
                    break;
                }
            for(int i=n-1; i>=0; i--)
                if(nums[i] == num)
                {
                    endIdx = i;
                    break;
                }
            ans = min(ans, endIdx - startIdx + 1);
        }
        return ans;
    }
};