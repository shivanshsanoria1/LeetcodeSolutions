class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n=nums.size();
        int subarrayCount = 0;
        unordered_set<string> s;

        for(int i=0; i<n; i++)
        {
            int pCount = 0;
            string hash = "";

            for(int j=i; j<n; j++)
            {
                if(nums[j] % p == 0)
                    pCount++;
                if(pCount > k)
                    break;

                hash += to_string(nums[j]) + "#";
                s.insert(hash);
            }
        }

        return s.size();
    }
};