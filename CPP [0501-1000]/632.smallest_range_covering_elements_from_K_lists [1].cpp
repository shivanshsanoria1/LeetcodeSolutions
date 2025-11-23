class Solution {
public:
    // T.C.=O(k*n*log(k*n)), S.C.=O(k*n)
    // k: size of nums, n: max size of nums[i]
    // Sorting + Sliding-window
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k=nums.size();
        // {num, list index}
        vector<pair<int, int>> numsk;
        for(int i=0; i<k; i++)
            for(int num: nums[i])
                numsk.push_back({num, i});
        
        // sort all values from k lists in increasing order
        sort(numsk.begin(), numsk.end());

        int left = 0, right = 0;
        vector<int> ans = {0, INT_MAX};
        // listFreq[i]: freq of elements from the ith list in curr window
        vector<int> listFreq(k, 0);
        // count of lists having atleast 1 element in curr window
        int listCount = 0;
        
        while(right < numsk.size())
        {
            auto [rightVal, rightIdx] = numsk[right];

            // increment the window size by 1
            // 1st element from 'rightIdx'th list inserted in curr window
            if(listFreq[rightIdx]++ == 0)
                listCount++;

            // keep shrinking the window until there are 
            // elements from less than k lists in curr window
            while(listCount == k)
            {
                auto [leftVal, leftIdx] = numsk[left];

                // smaller range found
                if(rightVal - leftVal < ans[1] - ans[0])
                {
                    ans[0] = leftVal;
                    ans[1] = rightVal;
                }

                // 'leftIdx'th list has no elements in curr window
                if(--listFreq[leftIdx] == 0)
                    listCount--;

                left++;
            }

            right++;
        }

        return ans;
    }
};