class Solution {
public:
    // T.C.=O(n^2), S.C.=O(k)
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n=nums.size();
        int count = 0;

        for(int i=0; i<n; i++)
        {
            unordered_set<int> s;
            
            for(int j=i; j<n; j++)
            {
                s.insert(nums[j]);

                if(s.size() == k)
                    count++;
                else if(s.size() > k)
                    break;
            }
        }

        return count;
    }
};