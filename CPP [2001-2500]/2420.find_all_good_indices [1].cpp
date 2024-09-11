class Solution {
public:
    // T.C.=O(n), S.C.=O(2*n)
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n=nums.size();

        vector<bool> prefix(n, false);
        vector<bool> postfix(n, false);

        int count = 1;
        for(int i=1; i<n; i++)
        {
            if(count >= k)
                prefix[i] = true;

            if(nums[i-1] >= nums[i])
                count++;
            else
                count = 1;
        }

        count = 1;
        for(int i=n-2; i>=0; i--)
        {
            if(count >= k)
                postfix[i] = true;
                
            if(nums[i] <= nums[i+1])
                count++;
            else
                count = 1;
        }

        vector<int> ans;
        for(int i=k; i < n-k; i++)
            if(prefix[i] && postfix[i])
                ans.push_back(i);
        
        return ans;
    }
};

/*
# prefix[i]: 
  whether there are atleast k consecutive 
  non-increasing elements before the index i
  
# postfix[i]: 
  whether there are atleast k consecutive 
  non-decreasing elements after the index i

# similar: [2100. find-good-days-to-rob-the-bank]
*/