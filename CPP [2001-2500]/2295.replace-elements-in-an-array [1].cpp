class Solution {
public:
    // T.C.=O(n + m), S.C.=O(n)
    // n: size of nums[], m: size of operations[]
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        // num -> index
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++)
            mp[nums[i]] = i;
        
        for(vector<int>& operation: operations)
        {
            int originalVal = operation[0];
            int newVal = operation[1];

            int idx = mp[originalVal];
            mp.erase(originalVal);
            mp[newVal] = idx;
            
            nums[idx] = newVal;
        }

        return nums;
    }
};