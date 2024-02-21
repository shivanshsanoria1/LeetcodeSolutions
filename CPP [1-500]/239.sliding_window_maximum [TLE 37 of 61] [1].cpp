class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) { //T.C.=O(nk) , S.C.=O(1)
        vector<int> ans;
        for(int i=0; i<nums.size()-k+1; i++)
        {
            int max_num=INT_MIN;
            for(int j=i; j<i+k; j++)
                max_num= max(max_num,nums[j]);
            ans.push_back(max_num);
        }
        return ans;
    }
};
//for n elements and window size k, num of windows=(n-k+1)