class Solution {
private:
    #define MOD int(1e9 + 7)

public:
    // T.C.=O(n^2), S.C.=O(1)
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            int left = i-1, right = i+1;
            // equality must be only checked in either left or right parts (not both)
            // to avoid the case of duplicate counting
            while(left >= 0 && arr[left] >= arr[i])
                left--;
            while(right < n && arr[right] > arr[i])
                right++;

            // count of continous nums which are >= arr[i] to the left of i
            int leftCount = i - left - 1;
            // count of continous nums which are >= arr[i] to the right of i
            int rightCount = right - i - 1;
            // num of subarrays which have arr[i] as the min num
            unsigned int freq = (leftCount + rightCount + (leftCount * rightCount) % MOD + 1) % MOD;

            ans = (ans + (arr[i]*freq) % MOD) % MOD;
        }
        return ans;
    }
};