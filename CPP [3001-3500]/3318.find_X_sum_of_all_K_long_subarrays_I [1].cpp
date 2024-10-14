class Solution {
public:
    // T.C.=O(n*(k*log(k) + x*log(k))), S.C.=O(k)
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;

        for(int i=0; i<=n-k; i++)
        {
            // num -> freq
            unordered_map<int, int> mp;
            for(int j=i; j<i+k; j++)
                mp[nums[j]]++;
            
            // max-heap; {freq, num}
            priority_queue<pair<int, int>> pq;
            for(auto [num, freq]: mp)
                pq.push({freq, num});
            
            int tempX = x;
            int xSum = 0;
            while(!pq.empty() && tempX--)
            {
                auto [freq, num] = pq.top();
                xSum += num * freq;
                pq.pop();
            }

            ans.push_back(xSum);
        }

        return ans;
    }
};