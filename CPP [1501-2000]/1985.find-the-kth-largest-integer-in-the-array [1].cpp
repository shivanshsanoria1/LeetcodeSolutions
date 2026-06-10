class Solution {
public:
    static bool cmp(string &s1, string &s2)
    {
        if(s1.length() == s2.length())
            return s1 < s2;
        return s1.size() < s2.size();
    }
    
    string kthLargestNumber(vector<string>& nums, int k) { //T.C.=O(nlogn)
        int n=nums.size();
        sort(nums.begin(),nums.end(),cmp);
        return nums[n-k];
    }
};