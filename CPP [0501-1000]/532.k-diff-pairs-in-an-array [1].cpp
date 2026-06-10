class Solution {
public:
    int findPairs(vector<int>& nums, int k) { // T.C.=O(n^2), S.C.=O(n^2)
        int n=nums.size();
        unordered_set<string> s;
        int count = 0;
        for(int i=0; i<n-1; i++)
            for(int j=i+1; j<n; j++)
                if(abs(nums[i] - nums[j]) == k)
                {
                    string hash1 = to_string(nums[i]) + "#" + to_string(nums[j]);
                    string hash2 = to_string(nums[j]) + "#" + to_string(nums[i]);
                    // hash1 and hash2 not found in set
                    if(s.find(hash1) == s.end() && s.find(hash2) == s.end())
                    {
                        s.insert(hash1);
                        s.insert(hash2);
                        count++;
                    }
                }
        return count;
    }
};