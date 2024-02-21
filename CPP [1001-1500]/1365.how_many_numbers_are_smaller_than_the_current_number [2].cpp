class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) { //T.C.=O(nlogn) , S.C.=O(n)
        int n=nums.size();
        vector<int> vec= nums; //make a copy of vector 'nums' in 'vec'
        sort(vec.begin(),vec.end());
        unordered_map<int,int> mp; //num -> count of numbers with value<=num
        for(int i=n-1; i>=0; i--)
            mp[vec[i]]=i;
        for(int i=0; i<n; i++)
            vec[i]=mp[nums[i]];
        return vec;
    }
};