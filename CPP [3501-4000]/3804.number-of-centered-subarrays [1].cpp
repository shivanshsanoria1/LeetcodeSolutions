class Solution {
public:
    // T.C.=O(n^2), S.C.=O(n)
    int centeredSubarrays(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for(int i=0; i<n; i++){
            int sum = 0;
            unordered_set<int> s;
            for(int j=i; j<n; j++){
                sum += nums[j];
                s.insert(nums[j]);

                if(s.find(sum) != s.end())
                    count++;
            }
        }

        return count;
    }
};