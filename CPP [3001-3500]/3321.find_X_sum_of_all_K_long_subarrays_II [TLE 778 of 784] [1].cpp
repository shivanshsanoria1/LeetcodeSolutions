class Solution {
public:
    // T.C.=O(k*log(k) + n*(log(k) + x)), S.C.=O(k)
    // fixed-length Sliding-window
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        // num -> freq
        unordered_map<int, int> mp;
        // max-heap; {freq, num}
        set<pair<int, int>> s;
        
        for(int i=0; i<k-1; i++)
            mp[nums[i]]++;
        
        for(auto [num, freq]: mp)
            s.insert({freq, num});

        int n = nums.size();
        int left = -1, right = k-1;
        vector<long long int> ans;
        
        while(right < n)
        {
            int oldFreq = 0;

            // remove the element at 'left' from window
            if(left >= 0)
            {
                oldFreq = mp[nums[left]];

                s.erase({oldFreq, nums[left]});

                if(--mp[nums[left]] == 0)
                    mp.erase(nums[left]);

                if(--oldFreq > 0)
                    s.insert({oldFreq, nums[left]});
            }
            
            // add the element at 'right' in window
            oldFreq = 0;

            if(mp.find(nums[right]) != mp.end())
            {
                oldFreq = mp[nums[right]];
                s.erase({oldFreq, nums[right]});
            }

            mp[nums[right]]++;
            s.insert({oldFreq + 1, nums[right]});
            
            // k pairs with the largest freq
            long long int xSum = 0;
            int tempX = x;
            for(auto itr = s.rbegin(); itr != s.rend() && tempX--; itr++)
            {
                int freq = itr->first;
                int num = itr->second;
                xSum += (long long int)num * freq;
            }

            ans.push_back(xSum);

            left++;
            right++;
        }

        return ans;
    }
};