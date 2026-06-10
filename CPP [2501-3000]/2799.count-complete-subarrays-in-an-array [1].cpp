class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) { // T.C.=O(n^2), S.C.=O(n)
        unordered_set<int> s(nums.begin(), nums.end());
        int n=nums.size();
        int count = 0;
        for(int i=0; i<n; i++)
        {
            unordered_set<int> temp;
            for(int j=i; j<n; j++)
            {
                temp.insert(nums[j]);
                if(temp.size() == s.size())
                {
                    count += n-j;
                    break;
                }
            }
        }
        return count;
    }
};