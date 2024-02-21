class Solution {
private:
    #define MOD int(1e9 + 7)

public:
    // T.C.=O(n), S.C.=O(n)
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        // stack stores index, not values
        stack<int> st;

        // count of continous nums which are >= arr[i] to the left of i
        vector<int> leftCounts(n, 0);
        for(int i=0; i<n; i++)
        {
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            leftCounts[i] = st.empty() ? i : i - st.top() - 1;
            st.push(i);
        }

        // clear stack
        while(!st.empty())
            st.pop();

        // count of continous nums which are >= arr[i] to the right of i
        vector<int> rightCounts(n, 0);
        for(int i=n-1; i>=0; i--)
        {
            while(!st.empty() && arr[st.top()] > arr[i])
                st.pop();
            rightCounts[i] = st.empty() ? n - i - 1 : st.top() - i - 1;
            st.push(i);
        }

        int ans = 0;
        for(int i=0; i<n; i++)
        {
            // num of subarrays which have arr[i] as the min num
            unsigned int freq = (leftCounts[i] + rightCounts[i] + (leftCounts[i] * rightCounts[i]) % MOD + 1) % MOD;
            ans = (ans + (arr[i]*freq) % MOD) % MOD;
        }
        return ans;
    }
    /*
    # equality must be only checked in either left or right parts (not both)
      to avoid the case of duplicate counting
    */
};