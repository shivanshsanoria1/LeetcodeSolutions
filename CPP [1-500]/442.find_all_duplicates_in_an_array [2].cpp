class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) { // T.C.=O(n) , S.C.=O(n)
        int n=nums.size();
        vector<int> ans, count(n+1,0);
        for(int i=0; i<n; i++)
            count[nums[i]]++;
        for(int i=1; i<n+1; i++)
            if(count[i]>1)
                ans.push_back(i);
        return ans;
    }
};