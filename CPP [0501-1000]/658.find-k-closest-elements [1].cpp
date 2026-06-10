class Solution {
public:
    // T.C.=O(n), S.C.=O(k)
    // 2-pointer
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        // index of element closest to x
        int idx = -1;

        if(x < arr[0])
            idx = 0;
        else if(x > arr[n-1])
            idx = n-1;
        else
        {
            int minAbsDiff = INT_MAX;
            for(int i=0; i<n; i++)
                if(abs(arr[i] - x) < minAbsDiff)
                {
                    minAbsDiff = abs(arr[i] - x);
                    idx = i;
                }

        }

        int left = idx - 1, right = idx + 1;
        vector<int> ans;
        ans.push_back(arr[idx]);
        vector<int> ans2;

        while(--k)
        {
            if(left >= 0 && right < n)
            {
                if(x - arr[left] <= arr[right] - x)
                    ans.push_back(arr[left--]);
                else
                    ans2.push_back(arr[right++]);
            }
            else if(left >= 0)
                ans.push_back(arr[left--]);
            else if(right < n)
                ans2.push_back(arr[right++]);
        }

        reverse(ans.begin(), ans.end());
        ans.insert(ans.end(), ans2.begin(), ans2.end());

        return ans;
    }
};