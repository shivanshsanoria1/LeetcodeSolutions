class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int n=nums.size();
        int count = 0;
        for(int i=0; i<n-1; i++)
        {
            int v1 = to_string(nums[i])[0] - '0';
            for(int j=i+1; j<n; j++)
            {
                int v2 = nums[j] % 10;
                if(__gcd(v1, v2) == 1)
                    count++;
            }
        }
        return count;
    }
};