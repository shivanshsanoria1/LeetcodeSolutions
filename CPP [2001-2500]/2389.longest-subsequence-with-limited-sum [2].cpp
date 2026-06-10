class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) { // T.C.=O(n*logn + q*logn), S.C.=O(n)
        sort(nums.begin(), nums.end());
        
        int n=nums.size();
        vector<int> preSum(n); // prefix sum
        preSum[0] = nums[0];
        for(int i=1; i<n; i++)
            preSum[i] = preSum[i-1] + nums[i];

        vector<int> ans;
        for(int qu: queries)
        {
            int idx = -1;
            int left = 0, right = n-1;
            while(left <= right)
            {
                int mid = left + (right - left) / 2;
                if(preSum[mid] == qu)
                {
                    idx = mid;
                    break;
                }
                else if(preSum[mid] < qu) // move to the right-subarray
                {
                    idx = mid;
                    left = mid + 1;
                }
                else // move to the left-subarray
                    right = mid - 1;
            }
            ans.push_back(idx + 1);
        }
        return ans;
    }
};