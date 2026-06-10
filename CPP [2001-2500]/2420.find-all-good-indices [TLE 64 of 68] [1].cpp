class Solution {
public:
    // T.C.=O(n*k), S.C.=O(1)
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans;

        for(int i=k; i < n - k; i++)
        {
            bool isGood = true;

            for(int j=i-2; j >= i - k; j--)
                if(nums[j] < nums[j+1])
                {
                    isGood = false;
                    break;
                }
            
            if(!isGood)
                continue;

            for(int j=i+2; j <= i + k; j++)
                if(nums[j-1] > nums[j])
                {
                    isGood = false;
                    break;
                }
            
            if(isGood)
                ans.push_back(i);
        }

        return ans;
    }
};

// similar: [2100. find-good-days-to-rob-the-bank]