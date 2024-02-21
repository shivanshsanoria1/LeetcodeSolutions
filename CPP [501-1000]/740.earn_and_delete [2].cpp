class Solution {
public:
    int deleteAndEarn(vector<int>& nums) { //T.C.=O(nlogn) , S.C.=O(n) ; DP (optimised)
        unordered_map<int,int> freq; //num -> freq
        for(int i=0; i<nums.size(); i++)
            freq[nums[i]]++;
        set<int> s(nums.begin(),nums.end());
        vector<int> vec(s.begin(),s.end()); //removed duplicates and sorted 'nums'
        int prev2=0, prev1=vec[0]*freq[vec[0]]; //prev2 ~ dp[i-2] , prev1 ~ dp[i-1]
        int curr;
        for(int i=1; i<vec.size(); i++)
        {
            curr = (vec[i]-vec[i-1]==1) ? max(prev1, vec[i]*freq[vec[i]] + prev2) : (prev1 + vec[i]*freq[vec[i]]);
            prev2=prev1; //move prev2 forward
            prev1=curr; //move prev1 forward
        }
        return prev1;
    }
};
// similar to Leetcode-198 (House Robber)
