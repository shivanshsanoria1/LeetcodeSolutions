class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) { //T.C.=O(n) , S.C.=O(n)
        vector<int> ans;
        int n=nums.size();
        vector<bool> vec(n+1,false); //keeps track of num appearing in array nums
        for(int i=0; i<n; i++)
            vec[nums[i]]=true;
        for(int i=1; i<n+1; i++)
            if(vec[i]==false)
                ans.push_back(i);
        return ans;
    }
};