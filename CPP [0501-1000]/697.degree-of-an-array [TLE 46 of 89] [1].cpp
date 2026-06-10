class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> mp; // num -> freq
        int degree = 0;
        for(int num: nums)
        {
            mp[num]++;
            degree = max(degree, mp[num]);
        }
        
        int n=nums.size();
        int ans = n;
        for(int i=0; i<n; i++)
        {
            mp.clear();
            int currDegree = 0;
            for(int j=i; j<n; j++)
            {
                mp[nums[j]]++;
                currDegree = max(currDegree, mp[nums[j]]);
                if(currDegree == degree)
                {
                    ans = min(ans, j - i + 1);
                    break;
                }
            }
        }
        return ans;
    }
};