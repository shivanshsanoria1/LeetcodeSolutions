class Solution {
public:
    int findLHS(vector<int>& nums) { // T.C.=O(n*logn), S.C.=O(1)
        sort(nums.begin(), nums.end());
        int freq1 = 1, freq2 = 0;
        bool found2nd = false;
        int ans = 0;
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i] == nums[i-1])
            {
                if(!found2nd)
                    freq1++;
                else
                    freq2++;
            }
            else
            {
                if(nums[i] - nums[i-1] == 1)
                {
                    if(!found2nd)
                        found2nd = true;
                    else
                        freq1 = freq2;
                    freq2 = 1;
                }
                else
                {
                    found2nd = false;
                    freq1 = 1;
                    freq2 = 0;
                }
            }
            if(found2nd) // 2nd num exists
                ans = max(ans, freq1 + freq2);
        }
        return ans;
    }
};